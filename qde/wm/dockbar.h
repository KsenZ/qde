/////////////////////////////////////////
//  File       : dockbar.cpp           //
//  Written by : g_cigala@virgilio.it  //
//  Modified by: ludmiloff@gmail.com   //
//  Copyright  : GPL                   //
/////////////////////////////////////////

// create the dockbar on bottom of the screen

#ifndef DOCKBAR_H
#define DOCKBAR_H

#include "defs.h"

class Client;
class DockbarItem;
class DockIcon; // REMOVE
class Adx;
class ClientIconProvider;

//typedef QList<DockIcon *> DockIconsList;

class Dockbar : public QDeclarativeView
{
    Q_OBJECT

public:
	Dockbar(Adx *a, QWidget *parent=0);
	~Dockbar();
	
	// Client management functions
    void addClient(Client *client);
    bool removeClient(Client *client);
	bool removeAll();

	// Launchers management functions
	void addLauncher(const QString &file);

	void readSettings();
	void saveSettings();

signals:
	void clientRemoved(Client *);

protected:
        virtual void dragEnterEvent(QDragEnterEvent *event);
        virtual void dropEvent(QDropEvent *event);
        virtual void resizeEvent (QResizeEvent * event);

private:
        QList<QObject*> DockbarItemList;
        ClientIconProvider *iconProvider;
};

#endif
 
