/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDRI2CONTEXT_H
#define QDRI2CONTEXT_H

#include <QtGui/QPlatformOpenGLContext>

struct xcb_dri2_dri2_buffer_t;

QT_BEGIN_NAMESPACE

class QXcbWindow;
class QDri2ContextPrivate;

class QDri2Context : public QPlatformOpenGLContext
{
    Q_DECLARE_PRIVATE(QDri2Context);
public:
    QDri2Context(QXcbWindow *window);
    ~QDri2Context();

    void makeCurrent();
    void doneCurrent();
    void swapBuffers();
    void* getProcAddress(const QString& procName);

    void resize(const QSize &size);

    QPlatformWindowFormat platformWindowFormat() const;

    void *eglContext() const;

protected:
    xcb_dri2_dri2_buffer_t *backBuffer();
    QScopedPointer<QDri2ContextPrivate> d_ptr;
private:
    Q_DISABLE_COPY(QDri2Context)
};

QT_END_NAMESPACE

#endif // QDRI2CONTEXT_H
