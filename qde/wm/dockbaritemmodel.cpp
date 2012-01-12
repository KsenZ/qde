#include "dockbaritemmodel.h"
#include "client.h"
#include <QDebug>

DockbarItemModel::DockbarItemModel(QObject *parent) :
    QAbstractListModel(parent)
{
    qDebug() << "Create DockbarItemModel";
    QHash<int, QByteArray> roles;
    roles[ClientRole] = "client";
    roles[AppNameRole] = "appname";
    roles[IconRole] = "icon";
    setRoleNames(roles);
}

QVariant DockbarItemModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "DockbarItemModel::data" << index << role;

    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid

    if (index.row() > (mItems.size()-1) )
        return QVariant();

    Client *client = mItems.at(index.row());

    switch (role) {
        case Qt::DisplayRole: // The default display role now displays the first name as well
        case ClientRole:
            return QVariant::fromValue(client);
        case AppNameRole:
            return QVariant::fromValue(client->appName);
        case IconRole:
            return QVariant::fromValue(client->appName);
        default:
            return QVariant();
        }

}

int DockbarItemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    //qDebug() << "DockbarItemModel count" << mItems.count();
    return mItems.count();
}

int DockbarItemModel::columnCount(const QModelIndex &parent) const
{
    qDebug() << "DockbarItemModel count column";
    Q_UNUSED(parent); return 1;
}

void DockbarItemModel::add(Client* client)
{
    qDebug() << "DockbarItemModel add" << client;
    if (!client || mItems.contains(client))
        return;

    // Append new item
    int first = mItems.count();
    int last = first;
    beginInsertRows(QModelIndex(), first, last);
    mItems.append(client);
    endInsertRows();

    //QModelIndex index = DockbarItemModel::index(mItems.count() -1,0);
    //qDebug() << "EMIT" << index;
    //emit dataChanged(index, index);

    //emit rowCountChanged(mItems.count() + 1);
}

void DockbarItemModel::remove(Client* client)
{
    qDebug() << "DockbarItemModel remove" << client;
    if (!client ||  !mItems.contains(client))
        return;


    //QModelIndex index = DockbarItemModel::index(mItems.indexOf(client));

    int first = mItems.indexOf(client);
    int last = first; // remove 1 element
    beginRemoveRows(QModelIndex(), first, last);
    mItems.removeOne(client);
    //emit dataChanged(index, index);
    endRemoveRows();

    //emit rowCountChanged(mItems.count() - 1);
}

Qt::ItemFlags DockbarItemModel::flags(const QModelIndex &index) const
{
    qDebug() << "DockbarItemModel flags";
    return index.flags();
}
