/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QWAYLANDQUICKHARDWARELAYER_P_H
#define QWAYLANDQUICKHARDWARELAYER_P_H

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

#include <QtWaylandCompositor/QWaylandQuickItem>

QT_BEGIN_NAMESPACE

class QWaylandQuickHardwareLayerPrivate;

class Q_WAYLANDCOMPOSITOR_EXPORT QWaylandQuickHardwareLayer : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_DECLARE_PRIVATE(QWaylandQuickHardwareLayer)
    Q_PROPERTY(int stackingLevel READ stackingLevel WRITE setStackingLevel NOTIFY stackingLevelChanged)
    QML_NAMED_ELEMENT(WaylandHardwareLayer)
    QML_ADDED_IN_VERSION(1, 2)
public:
    explicit QWaylandQuickHardwareLayer(QObject *parent = nullptr);
    ~QWaylandQuickHardwareLayer() override;

    int stackingLevel() const;
    void setStackingLevel(int level);

    QWaylandQuickItem *waylandItem() const;

    void classBegin() override;
    void componentComplete() override;

    void setSceneGraphPainting(bool);
    void initialize();

Q_SIGNALS:
    void stackingLevelChanged();
};

QT_END_NAMESPACE

#endif // QWAYLANDQUICKHARDWARELAYER_P_H
