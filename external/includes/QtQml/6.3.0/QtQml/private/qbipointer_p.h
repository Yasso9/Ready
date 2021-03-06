/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtQml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QBIPOINTER_P_H
#define QBIPOINTER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

namespace QtPrivate {
template <typename T> struct QFlagPointerAlignment
{
    enum : size_t { Value = Q_ALIGNOF(T) };
};
template <> struct QFlagPointerAlignment<void>
{
    enum : size_t { Value = ~size_t(0) };
};
}

/*!
    \internal
    \class template<typename T1, typename T2> QBiPointer<T1, T2>

    \short QBiPointer can be thought of as a space-optimized std::variant<T1*, T2*>
    with a nicer API to check the active pointer. Its other main feature is that
    it only requires sizeof(void *) space.

    \note It can also store one additional flag for a user defined purpose.
 */
template<typename T, typename T2>
class QBiPointer {
public:
    constexpr QBiPointer() noexcept = default;
    ~QBiPointer() noexcept = default;
    QBiPointer(const QBiPointer &o) noexcept = default;
    QBiPointer(QBiPointer &&o) noexcept = default;
    QBiPointer<T, T2> &operator=(const QBiPointer<T, T2> &o) noexcept = default;
    QBiPointer<T, T2> &operator=(QBiPointer<T, T2> &&o) noexcept = default;

    inline QBiPointer(T *);
    inline QBiPointer(T2 *);

    inline bool isNull() const;
    inline bool isT1() const;
    inline bool isT2() const;

    inline bool flag() const;
    inline void setFlag();
    inline void clearFlag();
    inline void setFlagValue(bool);

    inline QBiPointer<T, T2> &operator=(T *);
    inline QBiPointer<T, T2> &operator=(T2 *);

    friend inline bool operator==(QBiPointer<T, T2> ptr1, QBiPointer<T, T2> ptr2)
    {
        if (ptr1.isNull() && ptr2.isNull())
            return true;
        if (ptr1.isT1() && ptr2.isT1())
            return ptr1.asT1() == ptr2.asT1();
        if (ptr1.isT2() && ptr2.isT2())
            return ptr1.asT2() == ptr2.asT2();
        return false;
    }
    friend inline bool operator!=(QBiPointer<T, T2> ptr1, QBiPointer<T, T2> ptr2)
    {
        return !(ptr1 == ptr2);
    }

    friend inline void swap(QBiPointer<T, T2> &ptr1, QBiPointer<T, T2> &ptr2) noexcept
    {
        qSwap(ptr1.ptr_value, ptr2.ptr_value);
    }

    inline T *asT1() const;
    inline T2 *asT2() const;

private:
    quintptr ptr_value = 0;

    static const quintptr FlagBit = 0x1;
    static const quintptr Flag2Bit = 0x2;
    static const quintptr FlagsMask = FlagBit | Flag2Bit;
};

template<typename T, typename T2>
QBiPointer<T, T2>::QBiPointer(T *v)
: ptr_value(quintptr(v))
{
    Q_STATIC_ASSERT_X(QtPrivate::QFlagPointerAlignment<T>::Value >= 4,
                      "Type T does not have sufficient alignment");
    Q_ASSERT((quintptr(v) & FlagsMask) == 0);
}

template<typename T, typename T2>
QBiPointer<T, T2>::QBiPointer(T2 *v)
: ptr_value(quintptr(v) | Flag2Bit)
{
    Q_STATIC_ASSERT_X(QtPrivate::QFlagPointerAlignment<T2>::Value >= 4,
                      "Type T2 does not have sufficient alignment");
    Q_ASSERT((quintptr(v) & FlagsMask) == 0);
}

template<typename T, typename T2>
bool QBiPointer<T, T2>::isNull() const
{
    return 0 == (ptr_value & (~FlagsMask));
}

template<typename T, typename T2>
bool QBiPointer<T, T2>::isT1() const
{
    return !(ptr_value & Flag2Bit);
}

template<typename T, typename T2>
bool QBiPointer<T, T2>::isT2() const
{
    return ptr_value & Flag2Bit;
}

template<typename T, typename T2>
bool QBiPointer<T, T2>::flag() const
{
    return ptr_value & FlagBit;
}

template<typename T, typename T2>
void QBiPointer<T, T2>::setFlag()
{
    ptr_value |= FlagBit;
}

template<typename T, typename T2>
void QBiPointer<T, T2>::clearFlag()
{
    ptr_value &= ~FlagBit;
}

template<typename T, typename T2>
void QBiPointer<T, T2>::setFlagValue(bool v)
{
    if (v) setFlag();
    else clearFlag();
}

template<typename T, typename T2>
QBiPointer<T, T2> &QBiPointer<T, T2>::operator=(T *o)
{
    Q_ASSERT((quintptr(o) & FlagsMask) == 0);

    ptr_value = quintptr(o) | (ptr_value & FlagBit);
    return *this;
}

template<typename T, typename T2>
QBiPointer<T, T2> &QBiPointer<T, T2>::operator=(T2 *o)
{
    Q_ASSERT((quintptr(o) & FlagsMask) == 0);

    ptr_value = quintptr(o) | (ptr_value & FlagBit) | Flag2Bit;
    return *this;
}

template<typename T, typename T2>
T *QBiPointer<T, T2>::asT1() const
{
    Q_ASSERT(isT1());
    return (T *)(ptr_value & ~FlagsMask);
}

template<typename T, typename T2>
T2 *QBiPointer<T, T2>::asT2() const
{
    Q_ASSERT(isT2());
    return (T2 *)(ptr_value & ~FlagsMask);
}

QT_END_NAMESPACE

#endif // QBIPOINTER_P_H
