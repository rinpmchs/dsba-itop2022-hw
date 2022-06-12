#include "dishes.h"

Dishes::Dishes()//QObject *parent) // QStringListModel* model,
//    : QObject{parent}
//    , _model{model}
{

}


//void Dish::fillData(const QStringList& details)
//{
//    if (details.size() < 0)
//        throw std::invalid_argument("Invalid player description");
////    recipe_title = (QString)details[0];
//    url = (QString)details[1];
//    rating = details[2].toInt();
//    cuisine = (QString)details[3];//.toChar();
//    course = (QString)details[4];
//    diet = (QString)details[5];
////    prep_time = (int)details[6];
////    cook_time = (int)details[7];
////    ingredients = (QString)details[8];
//}

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
//        QList<QVariant> headers;
//        for(QString val : _headers)
//        {
//            headers.append(val);
//        }
//        _storage.append(headers);

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
