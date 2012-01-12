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
