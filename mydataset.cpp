#include "mydataset.h"
#include "dishes.h"

MyDataset::MyDataset(Dishes* dishes, QObject* parent)
    : QAbstractTableModel{parent}
    , _dishes {dishes}
{
}


int MyDataset::rowCount(const QModelIndex &parent) const
{
//    return _storage.size();
    return _dishes->getRow();
}


int MyDataset::columnCount(const QModelIndex &parent) const
{
//    return _dishes->getHeaders().size();
    return _dishes->getColumn();
}


QVariant MyDataset::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return _dishes->getVal(index);
    }
    else
        return QVariant();
}

QVariant MyDataset::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            return _dishes->getHeaders().at(section);
        }
    return QVariant();
}
