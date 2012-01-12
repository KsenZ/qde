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

class ClientIconProvider : public QDeclarativeImageProvider
{
public:
    static ClientIconProvider* instace(){
        static ClientIconProvider *singleton = new ClientIconProvider();
        return singleton;
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        qDebug() << "Request Pixmap" << id;

        QPixmap icon = mMap.value(id);

        if (!icon.isNull())
            return icon;

        icon = QIcon::fromTheme(id.toLower()).pixmap(128, 128);

        // Get default icon
        if (icon.isNull())
            icon = QIcon::fromTheme("application-x-executable").pixmap(128, 128);

        append(id, icon);
        return icon;
    }

    void append(const QString& appId, QPixmap pix){
        qDebug() << "ClientIconProvider: Appending" << appId;
        mMap.insert(appId, pix);
    }

private:
    ClientIconProvider() : QDeclarativeImageProvider(QDeclarativeImageProvider::Pixmap){};
    Q_DISABLE_COPY(ClientIconProvider)

    QMap<QString, QPixmap> mMap;
 };

#endif // DOCKBARCLIENTICONPROVIDER_H
