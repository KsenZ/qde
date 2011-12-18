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

#ifndef __DOCKBARQMLEXTENSION_H
#define __DOCKBARQMLEXTENSION_H

#include "defs.h"
#include "client.h"

class DockBarQMLExtension : public QObject
{
    Q_OBJECT

public:
    DockBarQMLExtension(QObject *parent) : QObject(parent){
        qRegisterMetaType<Client*>("Client*");
    }

    Q_INVOKABLE void removeClientFromDock(Client* client) const {
        if (client != 0)
            client->removeFromDock();
    }

    void showAboutDialog() { emit showAboutDlg(); }

signals:
    void showAboutDlg();

};

#endif // DOCKBARQMLEXTENSION_H
