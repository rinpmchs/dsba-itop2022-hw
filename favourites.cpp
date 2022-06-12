#include "favourites.h"

Favourites::Favourites()
{

}


int Favourites::rowCount(const QModelIndex &parent) const
{
//    return _storage.size();
    return _dishes->getRow();
}


int Favourites::columnCount(const QModelIndex &parent) const
{
//    return _dishes->getHeaders().size();
    return _dishes->getColumn();
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

QVariant Favourites::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            return _dishes->getHeaders().at(section);
        }
    return QVariant();
}
