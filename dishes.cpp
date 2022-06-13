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
            _cuisines.insert(lineToken[3]);
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
    return _favourites.at(index.row()).at(index.column());
}

void Dishes::addToFavourites(int selected)
{
    QList<QVariant> dish = _storage.at(selected);
    if(!(_favourites.contains(dish)))
    {
        _favourites.append(dish);
        return;
    }
    return;
}

void Dishes::deleteFromFavourites(int selected)
{
    QList<QVariant> dish = _storage.at(selected);
    _favourites.removeAt(selected);
}
