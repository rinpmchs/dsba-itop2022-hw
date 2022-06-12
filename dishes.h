#ifndef DISHES_H
#define DISHES_H

#include <QObject>
#include <QString>
#include <QStringListModel>
#include <QListView>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QTextStream>
#include <QStandardItem>
#include <QTextStream>


enum class DishFields
{
    recipe_title,
    url,
    rating,
    cuisine,
    course,
    diet,
    prep_time,
    cook_time,
    ingredients,
    COUNT
};

//class Dish
//{
//public:
////    Dish();
////    Dish(const QList<Dish>& data);

//    QList<QVariant> data;//();
//    QVariant recipe_title;//();
//    QVariant url;
//    QVariant rating;
//    QVariant cuisine;
//    QVariant course;
//    QVariant diet;
//    QVariant prep_time;
//    QVariant cook_time;
//    QList<QVariant> ingredients;

////    void fillData(const QStringList& details);
//};

class Dishes : public QObject
{
    Q_OBJECT
public:
    Dishes();
// explicit Dishes(QObject* parent);

public:
    bool loadFile(QFile& file);
    QVariant getVal(const QModelIndex& indx) { return _storage.at(indx.row()).at(indx.column()); }
    QStringList getHeaders() { return _headers; };
    int getRow();
    int getColumn();

    void addToFavourites(size_t);
    void deleteDish(QString);
    QVariant getFavourites(const QModelIndex& index);

protected:
//    QList<Dish>* _dishes;
    QStringList _headers = {}; //QList<QVariant>
    QList<QList<QVariant>> _storage; // QList<QStringList>
    QSet<QList<QVariant>> _favourites;

};

inline bool operator==(const QList<const QVariant>& dish1, const QList<const QVariant>& dish2)
{
    return dish1[0] == dish2[0];
}

inline uint qHash(const QVariant& dish){ return qHash(dish); }
//{
//    return qHash((dish[0], seed);
//}


//inline QHash<QString, QVariant> qHash(const QList<QVariant>&  dish)
//{
//    return dish[0].toHash();
//}


#endif // DISHES_H
