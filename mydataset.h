#ifndef MYDATASET_H
#define MYDATASET_H

#include "dishes.h"

#include <QAbstractTableModel>

class MyDataset: public QAbstractTableModel
{
public:
    MyDataset();
    explicit MyDataset(Dishes* dishes, QObject* parent = nullptr);


public:

private:
    Dishes* _dishes;

public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
//    bool setHeaderData(int section, Qt::Orientation orientation,
//                       const QVariant &value, int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QVariant getValueAtIndex(const QModelIndex& indx) { return _dishes->getVal(indx); };
};

#endif // MYDATASET_H