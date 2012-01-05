//////////////////////////////////////////
//  File       : dockbar.cpp		//
//  Written by : g_cigala@virgilio.it	//
//  Modified by: ludmiloff@gmail.com	//
//  Copyright  : GPL2			//
//////////////////////////////////////////

#include <QUrl>
#include <Mime>
#include "dockbar.h"
#include "adx.h"

#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include <QDesktopWidget>

#include "dockbaritem.h"
#include "dockbarclienticonprovider.h"
#include "dockbarqmlextension.h"

Dockbar::Dockbar(Adx *a, QWidget *parent) : QDeclarativeView(parent), iconProvider(new ClientIconProvider)
{   
    qDebug() << "Creating Dockbar";

    QDesktopWidget d;
    this->rootContext()->setContextProperty("screenHeight", d.height());
    this->rootContext()->setContextProperty("screenWidth", d.width());

    this->engine()->addImageProvider(QLatin1String("icons"), iconProvider);

    // Initialize empty dockbarModel
    this->rootContext()->setContextProperty("dockbarModel", QVariant::fromValue(DockbarItemList));
    this->rootContext()->setContextProperty("items",DockbarItemList.count());
    this->rootContext()->setContextProperty("dockbarExt", new DockBarQMLExtension(this));

    this->setSource(QUrl("qrc:/Dockbar.qml"));
    this->setResizeMode(SizeViewToRootObject);

    // Enable transparency
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->viewport()->setAutoFillBackground(false);
}

Dockbar::~Dockbar()
{
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
    DockbarItemList.append(new DockbarItem(client, iconProvider));
    this->rootContext()->setContextProperty("dockbarModel", QVariant::fromValue(DockbarItemList));
    this->rootContext()->setContextProperty("items",DockbarItemList.count());

}

bool Dockbar::removeClient(Client *client)
{
    qDebug() << "removeClient";
    QObject *item;

    foreach(item, DockbarItemList) {
        DockbarItem *i = qobject_cast<DockbarItem*>(item);
        if (i->client() == client) {
            DockbarItemList.removeOne(i);
            break;
        }
    }
    this->rootContext()->setContextProperty("dockbarModel", QVariant::fromValue(DockbarItemList));
    this->rootContext()->setContextProperty("items",DockbarItemList.count());
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
