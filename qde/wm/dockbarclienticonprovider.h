#ifndef DOCKBARCLIENTICONPROVIDER_H
#define DOCKBARCLIENTICONPROVIDER_H

#include <QDeclarativeImageProvider>
#include <QMap>
#include <QDebug>

class ClientIconProvider : public QDeclarativeImageProvider
{
public:
    static ClientIconProvider* instace(){
        static ClientIconProvider *singleton = new ClientIconProvider();
        return singleton;
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
    ClientIconProvider() : QDeclarativeImageProvider(QDeclarativeImageProvider::Pixmap){};
    Q_DISABLE_COPY(ClientIconProvider)

    QMap<QString, QPixmap> mMap;
 };

#endif // DOCKBARCLIENTICONPROVIDER_H
