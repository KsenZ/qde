/***************************************************************************
** This file is part of QDe
**
** Copyright (C) 2011,2012 Antonio Aloisio - gnuton@gnuton.org
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
****************************************************************************/

#ifndef DOCKBARCLIENTICONPROVIDER_H
#define DOCKBARCLIENTICONPROVIDER_H

#include <QDeclarativeImageProvider>
#include <QMap>
#include <QDebug>
#include <QIcon>
#include "adx.h"

class ClientIconProvider : public QDeclarativeImageProvider
{
public:
    ClientIconProvider() : QDeclarativeImageProvider(QDeclarativeImageProvider::Pixmap), a(0){
        a = qobject_cast<Adx*>(QApplication::instance());
    };

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        Q_UNUSED(size);
        Q_UNUSED(requestedSize)

        qDebug() << "Request Pixmap" << id;
        foreach(Client *c, a->clients){
            if (c->appName == id)
                return c->icon(128);
        }
        return QPixmap();
    }
private:
    Adx *a;
    Q_DISABLE_COPY(ClientIconProvider)
 };

#endif // DOCKBARCLIENTICONPROVIDER_H
