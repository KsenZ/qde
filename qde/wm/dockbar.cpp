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

#include <QUrl>
#include <Mime>
#include "dockbar.h"
#include "adx.h"

#include <QDeclarativeContext>
#include <QDeclarativeEngine>

//#include "dockbaritem.h"
#include "dockbaritemmodel.h"
#include "dockbarclienticonprovider.h"
#include "dockbarqmlextension.h"

Dockbar::Dockbar(Adx *a, QWidget *parent) : QDeclarativeView(parent)
{   
    qDebug() << "Creating Dockbar";

    this->rootContext()->setContextProperty("screenHeight", a->desktop->height());
    this->rootContext()->setContextProperty("screenWidth", a->desktop->width());

    this->engine()->addImageProvider(QLatin1String("icons"), ClientIconProvider::instace());

    // Initialize empty dockbarModel
    mModel = new DockbarItemModel(this);
    this->rootContext()->setContextProperty("dockbarModel", mModel);
    this->rootContext()->setContextProperty("dockbarExt", new DockBarQMLExtension(this));

    this->setSource(QUrl("qrc:/Dockbar.qml"));
    this->setResizeMode(SizeViewToRootObject);

    // Enable transparency
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->viewport()->setAutoFillBackground(false);
}

Dockbar::~Dockbar()
{
    delete ClientIconProvider::instace();
}

void Dockbar::readSettings()
{
    qDebug() << "READ SETTINGS";
/*
	app->stg->beginGroup("Dockbar");
        dockPix = app->stg->value("dock_pix", QCoreApplication::applicationDirPath() + "/../share/themes/antico/default/dockbar.png").toString();
	dockSizeFactor = app->stg->value("dock_factor", 100).toInt();
	setAnimSpeed(app->stg->value("dock_anim_factor", 0).toInt());
	autoHide = app->stg->value("dock_autohide", false).toBool();
	app->stg->endGroup(); //Dockbar
*/
}

void Dockbar::saveSettings()
{
    qDebug() << "Save settings";
/*
	app->stg->beginGroup("Dockbar");
	app->stg->setValue("dock_autohide", autoHide);	
	app->stg->endGroup();
	app->stg->sync();
*/
}

void Dockbar::addClient(Client *client)
{
    qDebug() << "Add Client" << client;
    mModel->add(client);
}

bool Dockbar::removeClient(Client *client)
{
    qDebug() << "removeClient";
    QObject *item;
    mModel->remove(client);
    //DockbarIte.append(new DockbarItem(client, iconProvider));

/*
    foreach(item, DockbarItemList) {
        DockbarItem *i = qobject_cast<DockbarItem*>(item);
        if (i->client() == client) {
            DockbarItemList.removeOne(i);
            break;
        }
    }
    */
}


bool Dockbar::removeAll()
{
    qDebug() << "removeAll";
    /*
	DockIcon *d;
	foreach(d, *iconsList)
	{
		d->client->mapFast();
		iconsList->removeOne(d);
		d->close();
		updateSize();
	}
        return true;
        */
}

void Dockbar::addLauncher(const QString &file)
{
    Q_UNUSED(file)
}

void Dockbar::showAboutDialog(){
    qDebug() << "DLG";

}

void Dockbar::dragEnterEvent(QDragEnterEvent *event)
{
    Q_UNUSED(event)
    /*
        if (event->mimeData()->hasUrls()) {
                event->acceptProposedAction();
        }
        */
}

void Dockbar::dropEvent(QDropEvent *event)
{
    Q_UNUSED(event)
    /*
    if (event->mimeData()->hasUrls()) {
        foreach (QUrl url, event->mimeData()->urls()) {
                qDebug() << url.path();
                AmeMime mime;
                qDebug() << mime.fromFileName(url.path());
        }
    }
    */
}

void Dockbar::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    qDebug() << "RESIZE" << event->size();

    // Set Geometry
    int maxW = QApplication::desktop()->width();
    int maxH = QApplication::desktop()->height();

    //Keeps dockbar in the right place
    this->setGeometry(QRect((maxW - width())/2, maxH - height(), width(), height()));
}
