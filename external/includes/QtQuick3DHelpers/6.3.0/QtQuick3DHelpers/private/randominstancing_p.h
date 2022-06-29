/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Quick 3D.
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

#ifndef RANDOMINSTANCING_P_H
#define RANDOMINSTANCING_P_H

#include <QtQuick3D/QQuick3DInstancing>

QT_BEGIN_NAMESPACE

class QQuick3DInstanceRange : public QQuick3DObject
{
    Q_OBJECT

    QML_ADDED_IN_VERSION(6, 2)
    Q_PROPERTY(QVariant from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QVariant to READ to WRITE setTo NOTIFY toChanged)
    Q_PROPERTY(bool proportional READ proportional WRITE setProportional NOTIFY proportionalChanged)
    QML_NAMED_ELEMENT(InstanceRange)

public:
    explicit QQuick3DInstanceRange(QQuick3DObject *parent = nullptr);
    ~QQuick3DInstanceRange() override {}
    QVariant from() const
    {
        return m_from;
    }
    QVariant to() const
    {
        return m_to;
    }

    bool proportional() const
    {
        return m_proportional;
    }

public Q_SLOTS:
    void setFrom(QVariant from);
    void setTo(QVariant to);
    void setProportional(bool proportional);

Q_SIGNALS:
    void fromChanged();
    void toChanged();
    void proportionalChanged();
    void changed();

protected:
    QSSGRenderGraphObject *updateSpatialNode(QSSGRenderGraphObject *) override
    {
        return nullptr;
    }
private:
    QVariant m_from;
    QVariant m_to;
    bool m_proportional = false;
};

class QRandomGenerator;
class QQuick3DRandomInstancing : public QQuick3DInstancing
{
    Q_OBJECT

    Q_PROPERTY(int instanceCount READ instanceCount WRITE setInstanceCount NOTIFY instanceCountChanged)
    Q_PROPERTY(QQuick3DInstanceRange *position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QQuick3DInstanceRange *scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(QQuick3DInstanceRange *rotation READ rotation WRITE setRotation NOTIFY rotationChanged)
    Q_PROPERTY(QQuick3DInstanceRange *color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(ColorModel colorModel READ colorModel WRITE setColorModel NOTIFY colorModelChanged)
    Q_PROPERTY(QQuick3DInstanceRange *customData READ customData WRITE setCustomData NOTIFY customDataChanged)

    Q_PROPERTY(int randomSeed READ randomSeed WRITE setRandomSeed NOTIFY randomSeedChanged)

    QML_NAMED_ELEMENT(RandomInstancing)
    QML_ADDED_IN_VERSION(6, 2)

public:
    enum class ColorModel { RGB, HSV, HSL };
    Q_ENUM(ColorModel)

    explicit QQuick3DRandomInstancing(QQuick3DObject *parent = nullptr);
    ~QQuick3DRandomInstancing();

    QByteArray getInstanceBuffer(int *instanceCount) override;

    int instanceCount() const
    {
        return m_randomCount;
    }

    int randomSeed() const
    {
        return m_randomSeed;
    }

    QQuick3DInstanceRange *position() const
    {
        return m_position;
    }

    QQuick3DInstanceRange* scale() const
    {
        return m_scale;
    }

    QQuick3DInstanceRange* rotation() const
    {
        return m_rotation;
    }

    QQuick3DInstanceRange* color() const
    {
        return m_color;
    }

    QQuick3DInstanceRange* customData() const
    {
        return m_customData;
    }

    ColorModel colorModel() const
    {
        return m_colorModel;
    }

public Q_SLOTS:
    void setInstanceCount(int instanceCount);
    void setRandomSeed(int randomSeed);

    void setPosition(QQuick3DInstanceRange *position);
    void setScale(QQuick3DInstanceRange *scale);
    void setRotation(QQuick3DInstanceRange *rotation);
    void setColor(QQuick3DInstanceRange *color);
    void setCustomData(QQuick3DInstanceRange *customData);
    void setColorModel(ColorModel colorModel);

Q_SIGNALS:
    void instanceCountChanged();
    void randomSeedChanged();
    void positionChanged();
    void scaleChanged();
    void rotationChanged();
    void colorChanged();
    void customDataChanged();
    void colorModelChanged();

private Q_SLOTS:
    void handleChange();

private:
    void generateInstanceTable();
    int m_randomCount = 0;
    int m_randomSeed = -1;
    bool m_dirty = true;
    QByteArray m_instanceData;
    QQuick3DInstanceRange *m_position = nullptr;
    QQuick3DInstanceRange *m_scale = nullptr;
    QQuick3DInstanceRange *m_rotation = nullptr;
    QQuick3DInstanceRange *m_color = nullptr;
    QQuick3DInstanceRange *m_customData = nullptr;
    ColorModel m_colorModel;
};
QT_END_NAMESPACE
#endif // RANDOMINSTANCING_P_H
