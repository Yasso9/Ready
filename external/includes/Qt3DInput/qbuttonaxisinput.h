/****************************************************************************
**
** Copyright (C) 2016 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
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

#ifndef QT3DINPUT_QBUTTONAXISINPUT_H
#define QT3DINPUT_QBUTTONAXISINPUT_H

#include <Qt3DInput/qt3dinput_global.h>
#include <Qt3DInput/QAbstractAxisInput>

QT_BEGIN_NAMESPACE

namespace Qt3DInput {

class QButtonAxisInputPrivate;

class Q_3DINPUTSHARED_EXPORT QButtonAxisInput : public QAbstractAxisInput
{
    Q_OBJECT
    Q_PROPERTY(float scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(QList<int> buttons READ buttons WRITE setButtons NOTIFY buttonsChanged)
    Q_PROPERTY(float acceleration READ acceleration WRITE setAcceleration NOTIFY accelerationChanged)
    Q_PROPERTY(float deceleration READ deceleration WRITE setDeceleration NOTIFY decelerationChanged)

public:
    explicit QButtonAxisInput(Qt3DCore::QNode *parent = nullptr);
    ~QButtonAxisInput();

    float scale() const;
    QList<int> buttons() const;

    float acceleration() const;
    float deceleration() const;

public Q_SLOTS:
    void setScale(float scale);
    void setButtons(const QList<int> &buttons);

    void setAcceleration(float acceleration);
    void setDeceleration(float deceleration);

Q_SIGNALS:
    void scaleChanged(float scale);
    void buttonsChanged(const QList<int> &buttons);

    void accelerationChanged(float acceleration);
    void decelerationChanged(float deceleration);

private:
    Q_DECLARE_PRIVATE(QButtonAxisInput)
};

} // Qt3DInput

QT_END_NAMESPACE

#endif // QT3DINPUT_QBUTTONAXISINPUT_H