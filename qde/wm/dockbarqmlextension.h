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
        qDebug() << "CLIENT" << client;
        if (client != 0)
            client->removeFromDock();
    }
};

Q_DECLARE_METATYPE(Client*)

#endif // DOCKBARQMLEXTENSION_H
