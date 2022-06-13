#ifndef FAVOURITES_H
#define FAVOURITES_H

#include "dishes.h"

#include <QAbstractTableModel>

class Favourites : public QAbstractTableModel
{
public:
    explicit Favourites(Dishes* dishes, QObject *parent = nullptr);

private:
    Dishes* _dishes;

public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant getFavouriteAtIndex(const QModelIndex& indx) { return _dishes->getFavourites(indx); };
};

#endif // FAVOURITES_H
