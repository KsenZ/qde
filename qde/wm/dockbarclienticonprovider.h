#ifndef DOCKBARCLIENTICONPROVIDER_H
#define DOCKBARCLIENTICONPROVIDER_H

#include <QDeclarativeImageProvider>
#include <QMap>
#include <QDebug>

class ClientIconProvider : public QDeclarativeImageProvider
{
public:
    ClientIconProvider() : QDeclarativeImageProvider(QDeclarativeImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        qDebug() << "Request Pixmap" << id;
        QString key = id;
        key.remove("image://icons/");
        QPixmap pixmap = mMap[key];

        return pixmap;
    }

    void append(const QString& appId, QPixmap pix){
        qDebug() << "ClientIconProvider: Appending" << appId;
        mMap.insert(appId, pix);
    }

private:
    QMap<QString, QPixmap> mMap;
 };

#endif // DOCKBARCLIENTICONPROVIDER_H
