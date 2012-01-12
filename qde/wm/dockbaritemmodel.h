#ifndef DOCKBARITEMMODEL_H
#define DOCKBARITEMMODEL_H

#include <QAbstractListModel>

//class DockbarItem;
class Client;
class DockbarItem;

class DockbarItemModel : public QAbstractListModel
{
    Q_OBJECT
    //Q_PROPERTY(int count READ count  NOTIFY rowCountChanged)

public:
    enum Roles {
             ClientRole = Qt::UserRole + 1,
             AppNameRole,
             IconRole
         };

    explicit DockbarItemModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void add(Client* client);
    void remove(Client* client);

signals:
    //void rowCountChanged(int count);

private:
    Q_DISABLE_COPY(DockbarItemModel);
    QList<Client*> mItems;
};

#endif // DOCKBARITEMMODEL_H
