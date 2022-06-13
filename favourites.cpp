#include "favourites.h"

Favourites::Favourites(Dishes* dishes, QObject *parent)
    : QAbstractTableModel{parent}
    , _dishes {dishes}
{
}


int Favourites::rowCount(const QModelIndex &parent) const
{
    return _dishes->getFavourites().size();
}


int Favourites::columnCount(const QModelIndex &parent) const
{
    return _dishes->getHeaders().size();
}


QVariant Favourites::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return _dishes->getFavourites(index);
    }
    else
        return QVariant();
}

//QVariant Favourites::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
//        {
//            return _dishes->getHeaders().at(section);
//        }
//    return QVariant();
//}
