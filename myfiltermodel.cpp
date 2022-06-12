#include "myfiltermodel.h"
#include <QRegularExpression>

MyFilterModel::MyFilterModel(QObject *parent)
    : QSortFilterProxyModel{parent}
    , _lunchEnabled(false)
    , _breakfastEnabled(false)
{

}


//void MyFilterModel::courseFiltering()
//{

//}


//void MyFilterModel::tableFiltering()
//{
//    QString regularExp;
//    if (_lunchEnabled)

//}
