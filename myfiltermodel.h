#ifndef MYFILTERMODEL_H
#define MYFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

class MyFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit MyFilterModel(QObject *parent = nullptr);

public:
//    void tableFiltering();
//    void courseFiltering();

private:
    bool _lunchEnabled;
    bool _breakfastEnabled;

signals:

};

#endif // MYFILTERMODEL_H
