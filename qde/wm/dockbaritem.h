#ifndef DOCKBARITEM_H
#define DOCKBARITEM_H

#include <QObject>
#include <QDebug>

#include "client.h"
#include "dockbarclienticonprovider.h"

class DockbarItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(Client* client READ client WRITE setClient NOTIFY clientChanged)

public:
    DockbarItem(const QString& name, const QString& icon) : QObject(){
        setName(name);
        setIcon(icon);
    };

    DockbarItem(Client* client, ClientIconProvider *icons) : QObject(){
        setName(client->appName);
        icons->append(client->appName, client->appIcon);
        mIcon = client->appName;
        mClient = client;
    }

    QString name(){ return mName;};
    void setName(const QString& name){ mName = name; };

    QString icon() { return mIcon; };
    void setIcon(const QString& icon){ mIcon = icon; };

    Client* client() { return mClient; };
    void setClient(Client* client){ mClient = client; };

signals:
    void nameChanged(const QString& name);
    void iconChanged(const QString& icon);
    void clientChanged(Client *);

private:
    QString mName;
    QString mIcon;
    Client* mClient;
};

#endif // DOCKBARITEM_H
