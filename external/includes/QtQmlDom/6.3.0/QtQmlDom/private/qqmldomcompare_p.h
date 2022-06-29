/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
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
**/
#ifndef QMLDOMCOMPARE_P_H
#define QMLDOMCOMPARE_P_H

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

#include "qqmldom_global.h"
#include "qqmldomitem_p.h"

#include <memory>

QT_BEGIN_NAMESPACE

namespace QQmlJS {
namespace Dom {

bool domCompare(
        DomItem &i1, DomItem &i2, function_ref<bool(Path, DomItem &, DomItem &)> change,
        function_ref<bool(DomItem &, const PathEls::PathComponent &, DomItem &)> filter = noFilter,
        Path p = Path());

enum DomCompareStrList { FirstDiff, AllDiffs };

QMLDOM_EXPORT QStringList domCompareStrList(
        DomItem &i1, DomItem &i2,
        function_ref<bool(DomItem &, const PathEls::PathComponent &, DomItem &)> filter = noFilter,
        DomCompareStrList stopAtFirstDiff = DomCompareStrList::FirstDiff);

inline QStringList domCompareStrList(
        MutableDomItem &i1, DomItem &i2,
        function_ref<bool(DomItem &, const PathEls::PathComponent &, DomItem &)> filter = noFilter,
        DomCompareStrList stopAtFirstDiff = DomCompareStrList::FirstDiff)
{
    DomItem ii1 = i1.item();
    return domCompareStrList(ii1, i2, filter, stopAtFirstDiff);
}

inline QStringList domCompareStrList(
        DomItem &i1, MutableDomItem &i2,
        function_ref<bool(DomItem &, const PathEls::PathComponent &, DomItem &)> filter = noFilter,
        DomCompareStrList stopAtFirstDiff = DomCompareStrList::FirstDiff)
{
    DomItem ii2 = i2.item();
    return domCompareStrList(i1, ii2, filter, stopAtFirstDiff);
}

inline QStringList domCompareStrList(
        MutableDomItem &i1, MutableDomItem &i2,
        function_ref<bool(DomItem &, const PathEls::PathComponent &, DomItem &)> filter = noFilter,
        DomCompareStrList stopAtFirstDiff = DomCompareStrList::FirstDiff)
{
    DomItem ii1 = i1.item();
    DomItem ii2 = i2.item();
    return domCompareStrList(ii1, ii2, filter, stopAtFirstDiff);
}

} // end namespace Dom
} // end namespace QQmlJS

QT_END_NAMESPACE
#endif // QMLDOMCOMPARE_P_H