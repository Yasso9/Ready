/****************************************************************************
**
** Copyright (C) 2019 The Qt Company Ltd.
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

#ifndef QOPCUAAPPLICATIONRECORDDATATYPE_H
#define QOPCUAAPPLICATIONRECORDDATATYPE_H

#include <QtOpcUa/qopcuaglobal.h>
#include <QtOpcUa/qopcualocalizedtext.h>
#include <QtOpcUa/qopcuaapplicationdescription.h>

#include <QtCore/qshareddata.h>
#include <QtCore/qvariant.h>

QT_BEGIN_NAMESPACE

class QOpcUaApplicationRecordDataTypeData;
class Q_OPCUA_EXPORT QOpcUaApplicationRecordDataType
{
public:
    QOpcUaApplicationRecordDataType();
    QOpcUaApplicationRecordDataType(const QOpcUaApplicationRecordDataType &);
    QOpcUaApplicationRecordDataType &operator=(const QOpcUaApplicationRecordDataType &);
    bool operator==(const QOpcUaApplicationRecordDataType &rhs) const;
    operator QVariant() const;
    ~QOpcUaApplicationRecordDataType();

    void setApplicationId(const QString &nodeId);
    const QString &applicationId() const;

    void setApplicationType(QOpcUaApplicationDescription::ApplicationType applicationType);
    QOpcUaApplicationDescription::ApplicationType applicationType() const;

    void setApplicationUri(const QString &applicationUri);
    const QString &applicationUri() const;

    void setApplicationNames(const QList<QOpcUaLocalizedText> &applicationNames);
    const QList<QOpcUaLocalizedText> &applicationNames() const;

    void setProductUri(const QString &productUri);
    const QString &productUri() const;

    void setDiscoveryUrls(const QList<QString> &discoveryUrls);
    const QList<QString> &discoveryUrls() const;

    void setServerCapabilityIdentifiers(const QList<QString> &serverCapabilityIdentifiers);
    const QList<QString> &serverCapabilityIdentifiers() const;

private:
    QSharedDataPointer<QOpcUaApplicationRecordDataTypeData> data;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QOpcUaApplicationRecordDataType)

#endif // QOPCUAAPPLICATIONRECORDDATATYPE_H
