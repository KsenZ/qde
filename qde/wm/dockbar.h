/***************************************************************************
** This file is part of QDe
**
** Copyright (C) 2011,2012 Antonio Aloisio - gnuton@gnuton.org
** Copyright (C) Cvetoslac Ludmiloff - ludmiloff@gmail.com
** Copyright (C) Giuseppe Cigala - g_cigala@virgilio.it
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


// create the dockbar on bottom of the screen

#ifndef DOCKBAR_H
#define DOCKBAR_H

#include "defs.h"

class Client;
class Adx;
class ClientIconProvider;
class DockBarQMLExtension;
class DockbarItemModel;

class Dockbar : public QDeclarativeView
{
    Q_OBJECT

public:
	Dockbar(Adx *a, QWidget *parent=0);
	~Dockbar();
	
	// Client management functions
    void addClient(Client *client);
    void removeClient(Client *client);
    void removeAll();

	// Launchers management functions
	void addLauncher(const QString &file);

    void showAboutDialog();

signals:
	void clientRemoved(Client *);

protected:
        virtual void dragEnterEvent(QDragEnterEvent *event);
        virtual void dropEvent(QDropEvent *event);
        virtual void resizeEvent (QResizeEvent * event);

private:
        DockbarItemModel *mModel;
        DockBarQMLExtension *mQmlExtender;
};

#endif
 
