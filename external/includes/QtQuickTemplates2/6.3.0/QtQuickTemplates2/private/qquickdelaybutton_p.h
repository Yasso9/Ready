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

#ifndef QQUICKDELAYBUTTON_P_H
#define QQUICKDELAYBUTTON_P_H

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

#include <QtQuickTemplates2/private/qquickabstractbutton_p.h>

QT_BEGIN_NAMESPACE

class QQuickTransition;
class QQuickDelayButtonPrivate;

class Q_QUICKTEMPLATES2_PRIVATE_EXPORT QQuickDelayButton : public QQuickAbstractButton
{
    Q_OBJECT
    Q_PROPERTY(int delay READ delay WRITE setDelay NOTIFY delayChanged FINAL)
    Q_PROPERTY(qreal progress READ progress WRITE setProgress NOTIFY progressChanged FINAL)
    Q_PROPERTY(QQuickTransition *transition READ transition WRITE setTransition NOTIFY transitionChanged FINAL)
    QML_NAMED_ELEMENT(DelayButton)
    QML_ADDED_IN_VERSION(2, 2)

public:
    explicit QQuickDelayButton(QQuickItem *parent = nullptr);

    int delay() const;
    void setDelay(int delay);

    qreal progress() const;
    void setProgress(qreal progress);

    QQuickTransition *transition() const;
    void setTransition(QQuickTransition *transition);

Q_SIGNALS:
    void activated();
    void delayChanged();
    void progressChanged();
    void transitionChanged();

protected:
    void buttonChange(ButtonChange change) override;
    void nextCheckState() override;

    QFont defaultFont() const override;

private:
    Q_DISABLE_COPY(QQuickDelayButton)
    Q_DECLARE_PRIVATE(QQuickDelayButton)
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QQuickDelayButton)

#endif // QQUICKDELAYBUTTON_P_H
