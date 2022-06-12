#include "dishes.h"

Dishes::Dishes()
{
}

int Dishes::getRow()
{
    return _storage.size();
}

int Dishes::getColumn()
{
//    return (int)DishFields::COUNT;
    return _headers.size();
}


bool Dishes::loadFile(QFile& file)
{
    if (file.open(QIODevice::ReadOnly))
    {
        size_t lineindex = 0;
        QTextStream in(&file);
        QString fileLine = in.readLine();

        _headers = fileLine.split(";", Qt::SkipEmptyParts);

        while (!in.atEnd())
        {
            QList<QVariant> dish;
            fileLine = in.readLine();
            QStringList lineToken = fileLine.split(";", Qt::SkipEmptyParts);
            for(QString val : lineToken)
            {
                dish.append(val);
            }
            _storage.append(dish);
            lineindex++;
        }
        file.close();
        return true;
    }
    return false;
}


QVariant Dishes::getFavourites(const QModelIndex& index)
{
    return _favourites.at(index.row()).at(index.column());//values().at(index.row()).at(index.column());
}

void Dishes::addToFavourites(size_t index)
{
    QList<QVariant> dish = _storage.at(index - 1);
    _favourites.append(dish);
}

//void Dishes::deleteDish(QString dishName)
//{
//    for (QList<QVariant>& dish : _storage)
//    {
//        if (dish[0] == dishName)
//            _storage.erase(&dish);
//    }
//}

