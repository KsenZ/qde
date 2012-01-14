/***************************************************************************
** This file is part of QDe
**
** Copyright (C) 2011,2012 Antonio Aloisio - gnuton@gnuton.org
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
****************************************************************************/

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
    QList<Client*> removeAll();

signals:
    //void rowCountChanged(int count);

private:
    Q_DISABLE_COPY(DockbarItemModel);
    QList<Client*> mItems;
};

#endif // DOCKBARITEMMODEL_H
