#include <QtDBus>
#include "sysmenu.h"
#include "panel.h"
#include "aboutdlg.h"
#include "adx.h"
 
SystemMenu::SystemMenu(Adx *a, Panel *p, QWidget *parent)
	: GenericButton(p, parent) 
{
	app = a;

	setFixedWidth(28);

	setIconSize(QSize(17, 16));
	setImages(QPixmap(":/default/ame-logo.png"), QPixmap(":/default/ame-logo-active.png"));
	rebuildMenu();
}

void SystemMenu::rebuildMenu(bool dockHiding)
{
	if (menu()) {
		menu()->clear();
	}
	
	QMenu *menu = new QMenu(this);

	about = new QAction("About this computer", this);
	menu->addAction(about);
	connect(about, SIGNAL(triggered()), this, SLOT(onAbout()));

/* TODO: Removed for now until I found clear way for managing software on different distros 
	QAction *software = new QAction("Software management ...", this);
	menu->addAction(software);
*/
	menu->addSeparator();

	QAction *pref = new QAction("System preferences ...", this);
	menu->addAction(pref);
	connect(pref, SIGNAL(triggered()), this, SLOT(onPreferences()));

	menu->addSeparator();

/* TODO: Removed for now until I implement the features

	QAction *force_quit = new QAction("Force Quit ...", this);
	menu->addAction(force_quit);
	menu->addSeparator();
*/
	sleep = new QAction("Sleep", this);
	menu->addAction(sleep);
	connect(sleep, SIGNAL(triggered()), this, SLOT(onSleep()));

	restart = new QAction("Restart ...", this);
	menu->addAction(restart);
	connect(restart, SIGNAL(triggered()), this, SLOT(onRestart()));

	shutdown = new QAction("Shutdown ...", this);
	menu->addAction(shutdown);
	connect(shutdown, SIGNAL(triggered()), this, SLOT(onShutdown()));

	menu->addSeparator();
	logout = new QAction("Logout ...", this);
	menu->addAction(logout);
	connect(logout, SIGNAL(triggered()), this, SLOT(onLogout()));

	setMenu(menu);
	
	connect(this, SIGNAL(clicked()), this, SLOT(showMenu()));
}

void SystemMenu::onAbout()
{
	app->onAbout();
}

void SystemMenu::onPreferences()
{
	QProcess::startDetached("syspref.app");
}

void SystemMenu::onDockPref()
{
	QProcess::startDetached("syspref.app -w 3");	
}

void SystemMenu::onLogout()
{
	app->onLogout();
}

void SystemMenu::onRestart()
{
	app->onPCRestart();
}

void SystemMenu::onShutdown()
{	app->onPCShutdown();
}

void SystemMenu::onSleep()
{
	app->onPCSleep();
}

SystemMenu::~SystemMenu()
{
}

