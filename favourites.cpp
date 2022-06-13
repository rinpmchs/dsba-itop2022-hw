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
