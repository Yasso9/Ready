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

#ifndef QQUICKPOPUPITEM_P_P_H
#define QQUICKPOPUPITEM_P_P_H

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

#include <QtQuickTemplates2/private/qquickpage_p.h>
#include <QtQuickTemplates2/private/qquickpage_p_p.h>

QT_BEGIN_NAMESPACE

class QQuickPopup;
class QQuickPopupItemPrivate;

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT QQuickPopupItem : public QQuickPage
{
    Q_OBJECT

public:
    explicit QQuickPopupItem(QQuickPopup *popup);

    void grabShortcut();
    void ungrabShortcut();

protected:
    void updatePolish() override;

    bool event(QEvent *event) override;
    bool childMouseEventFilter(QQuickItem *child, QEvent *event) override;
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseUngrabEvent() override;
#if QT_CONFIG(quicktemplates2_multitouch)
    void touchEvent(QTouchEvent *event) override;
    void touchUngrabEvent() override;
#endif
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif

    void contentItemChange(QQuickItem *newItem, QQuickItem *oldItem) override;
    void contentSizeChange(const QSizeF &newSize, const QSizeF &oldSize) override;
    void fontChange(const QFont &newFont, const QFont &oldFont) override;
    void geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry) override;
    void localeChange(const QLocale &newLocale, const QLocale &oldLocale) override;
    void mirrorChange() override;
    void itemChange(ItemChange change, const ItemChangeData &data) override;
    void paddingChange(const QMarginsF &newPadding, const QMarginsF &oldPadding) override;
    void enabledChange() override;

    QFont defaultFont() const override;

#if QT_CONFIG(accessibility)
    QAccessible::Role accessibleRole() const override;
    void accessibilityActiveChanged(bool active) override;
#endif

private:
    Q_DISABLE_COPY(QQuickPopupItem)
    Q_DECLARE_PRIVATE(QQuickPopupItem)
    friend class QQuickPopup;
};

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT QQuickPopupItemPrivate : public QQuickPagePrivate
{
    Q_DECLARE_PUBLIC(QQuickPopupItem)

public:
    QQuickPopupItemPrivate(QQuickPopup *popup);

    void implicitWidthChanged() override;
    void implicitHeightChanged() override;

    void resolveFont() override;

    QQuickItem *getContentItem() override;

    void cancelContentItem() override;
    void executeContentItem(bool complete = false) override;

    void cancelBackground() override;
    void executeBackground(bool complete = false) override;

    QQuickPalette *palette() const override;
    void setPalette(QQuickPalette* p) override;
    void resetPalette() override;

    QPalette defaultPalette() const override;
    bool providesPalette() const override;

    QPalette parentPalette() const override;

    int backId = 0;
    int escapeId = 0;
    QQuickPopup *popup = nullptr;
};

QT_END_NAMESPACE

#endif // QQUICKPOPUPITEM_P_P_H
