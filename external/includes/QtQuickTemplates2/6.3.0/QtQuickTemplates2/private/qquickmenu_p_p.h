/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
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

#ifndef QQUICKMENU_P_P_H
#define QQUICKMENU_P_P_H

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

#include <QtCore/qlist.h>
#include <QtCore/qpointer.h>

#include <QtQuickTemplates2/private/qquickmenu_p.h>
#include <QtQuickTemplates2/private/qquickpopup_p_p.h>

QT_BEGIN_NAMESPACE

class QQuickAction;
class QQmlComponent;
class QQmlObjectModel;
class QQuickMenuItem;

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT QQuickMenuPrivate : public QQuickPopupPrivate
{
public:
    Q_DECLARE_PUBLIC(QQuickMenu)

    QQuickMenuPrivate();

    static QQuickMenuPrivate *get(QQuickMenu *menu)
    {
        return menu->d_func();
    }

    void init();

    QQuickItem *itemAt(int index) const;
    void insertItem(int index, QQuickItem *item);
    void moveItem(int from, int to);
    void removeItem(int index, QQuickItem *item);

    QQuickItem *beginCreateItem();
    void completeCreateItem();

    QQuickItem *createItem(QQuickMenu *menu);
    QQuickItem *createItem(QQuickAction *action);

    void resizeItem(QQuickItem *item);
    void resizeItems();

    void itemChildAdded(QQuickItem *item, QQuickItem *child) override;
    void itemSiblingOrderChanged(QQuickItem *item) override;
    void itemParentChanged(QQuickItem *item, QQuickItem *parent) override;
    void itemDestroyed(QQuickItem *item) override;
    void itemGeometryChanged(QQuickItem *, QQuickGeometryChange change, const QRectF &diff) override;

    QQuickPopupPositioner *getPositioner() override;
    bool prepareEnterTransition() override;
    bool prepareExitTransition() override;
    bool blockInput(QQuickItem *item, const QPointF &point) const override;

    void onItemHovered();
    void onItemTriggered();
    void onItemActiveFocusChanged();

    QQuickMenu *currentSubMenu() const;
    void setParentMenu(QQuickMenu *parent);
    void resolveParentItem();

    void propagateKeyEvent(QKeyEvent *event);

    void startHoverTimer();
    void stopHoverTimer();

    void setCurrentIndex(int index, Qt::FocusReason reason);
    bool activateNextItem();
    bool activatePreviousItem();

    QQuickMenuItem *firstEnabledMenuItem() const;

    static void contentData_append(QQmlListProperty<QObject> *prop, QObject *obj);
    static qsizetype contentData_count(QQmlListProperty<QObject> *prop);
    static QObject *contentData_at(QQmlListProperty<QObject> *prop, qsizetype index);
    static void contentData_clear(QQmlListProperty<QObject> *prop);

    QPalette defaultPalette() const override;

    bool cascade = false;
    int hoverTimer = 0;
    int currentIndex = -1;
    qreal overlap = 0;
    QPointer<QQuickMenu> parentMenu;
    QPointer<QQuickMenuItem> currentItem;
    QQuickItem *contentItem = nullptr; // TODO: cleanup
    QList<QObject *> contentData;
    QQmlObjectModel *contentModel;
    QQmlComponent *delegate = nullptr;
    QString title;
};

QT_END_NAMESPACE

#endif // QQUICKMENU_P_P_H
