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

#include <Qt3DCore/qt3dcore-config.h>

#ifndef QT3DCORE_DEBUG_ASPECTCOMMANDDEBUGGER_H
#define QT3DCORE_DEBUG_ASPECTCOMMANDDEBUGGER_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QTcpServer>
#include <Qt3DCore/private/qt3dcore_global_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DCore {

class QSystemInformationService;

namespace Debug {

class AsynchronousCommandReply;

class Q_3DCORE_PRIVATE_EXPORT AspectCommandDebugger : public QTcpServer
{
    Q_OBJECT
public:
    explicit AspectCommandDebugger(QSystemInformationService *parent = nullptr);

    void initialize();

    struct Q_3DCORE_PRIVATE_EXPORT ReadBuffer {
        QByteArray buffer;
        int startIdx = 0;
        int endIdx = 0;

        inline int size() const { return endIdx - startIdx; }
        void insert(const QByteArray &array);
        void trim();
    };

private Q_SLOTS:
    void asynchronousReplyFinished(AsynchronousCommandReply *reply);

private:
    void sendReply(QTcpSocket *socket, const QByteArray &data);
    void onCommandReceived(QTcpSocket *socket);
    void executeCommand(const QString &command, QTcpSocket *socket);

    QList<QTcpSocket *> m_connections;
    QSystemInformationService *m_service;

    ReadBuffer m_readBuffer;
    QHash<AsynchronousCommandReply *, QTcpSocket *> m_asyncCommandToSocketEntries;
};

} // Debug

} // Qt3DCore

QT_END_NAMESPACE

#endif // QT3DCORE_DEBUG_ASPECTCOMMANDDEBUGGER_H
