/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Quick Templates 2 module of the Qt Toolkit.
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

#ifndef QQUICKSWIPEDELEGATE_P_H
#define QQUICKSWIPEDELEGATE_P_H

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

#include <QtQuickTemplates2/private/qquickitemdelegate_p.h>

QT_BEGIN_NAMESPACE

class QQuickSwipe;
class QQuickSwipeDelegatePrivate;
class QQuickSwipeDelegateAttached;
class QQuickSwipeDelegateAttachedPrivate;

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT QQuickSwipeDelegate : public QQuickItemDelegate
{
    Q_OBJECT
    Q_PROPERTY(QQuickSwipe *swipe READ swipe CONSTANT FINAL)
    QML_NAMED_ELEMENT(SwipeDelegate)
    QML_ATTACHED(QQuickSwipeDelegateAttached)
    QML_ADDED_IN_VERSION(2, 0)

public:
    explicit QQuickSwipeDelegate(QQuickItem *parent = nullptr);

    QQuickSwipe *swipe() const;

    enum Side { Left = 1, Right = -1 };
    Q_ENUM(Side)

    static QQuickSwipeDelegateAttached *qmlAttachedProperties(QObject *object);

protected:
    bool childMouseEventFilter(QQuickItem *child, QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseUngrabEvent() override;
    void touchEvent(QTouchEvent *event) override;

    void componentComplete() override;
    void geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry) override;

    QFont defaultFont() const override;

#if QT_CONFIG(accessibility)
    QAccessible::Role accessibleRole() const override;
#endif

private:
    Q_DISABLE_COPY(QQuickSwipeDelegate)
    Q_DECLARE_PRIVATE(QQuickSwipeDelegate)
};

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT QQuickSwipeDelegateAttached : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool pressed READ isPressed NOTIFY pressedChanged FINAL)

public:
    explicit QQuickSwipeDelegateAttached(QObject *object = nullptr);

    bool isPressed() const;
    void setPressed(bool pressed);

Q_SIGNALS:
    void pressedChanged();
    void clicked();

private:
    Q_DISABLE_COPY(QQuickSwipeDelegateAttached)
    Q_DECLARE_PRIVATE(QQuickSwipeDelegateAttached)
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QQuickSwipeDelegate)
QML_DECLARE_TYPEINFO(QQuickSwipeDelegate, QML_HAS_ATTACHED_PROPERTIES)
Q_DECLARE_METATYPE(QQuickSwipeDelegate::Side)

#endif // QQUICKSWIPEDELEGATE_P_H
