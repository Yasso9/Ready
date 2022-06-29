/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt OPC UA module.
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

#pragma once

#include <private/universalnode_p.h>

#include <QObject>
#include <QPointer>

#include "qopcuatype.h"
#include "qopcuabrowsepathtarget.h"
#include "qopcuarelativepathelement.h"

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

QT_BEGIN_NAMESPACE

class QOpcUaNode;
class QOpcUaClient;
class OpcUaRelativeNodeId;
class QOpcUaClient;

class OpcUaPathResolver : public QObject
{
    Q_OBJECT
public:
    OpcUaPathResolver(OpcUaRelativeNodeId *relativeNode, QOpcUaClient *client, QObject *target);
    ~OpcUaPathResolver();
    void startResolving();

signals:
    void resolvedStartNode(const UniversalNode &nodeId, const QString &errorMessage);
    void resolvedNode(UniversalNode node, QString errorMessage);

private slots:
    void startNodeResolved(UniversalNode startNode, const QString &errorMessage);
    void browsePathFinished(QList<QOpcUaBrowsePathTarget> results, QList<QOpcUaRelativePathElement> path, QOpcUa::UaStatusCode status);

private:
    OpcUaPathResolver(int level, OpcUaRelativeNodeId *relativeNode, QOpcUaClient *client, QObject *target);

    int m_level;
    QPointer<OpcUaRelativeNodeId> m_relativeNode;
    QPointer<QObject> m_target;
    QPointer<QOpcUaClient> m_client;
    QOpcUaNode *m_node;
};

QT_END_NAMESPACE
