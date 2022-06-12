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

protected:
//    QList<Dish>* _dishes;
    QStringList _headers = {}; //QList<QVariant>
    QList<QList<QVariant>> _storage; // QList<QStringList>

};

#endif // DISHES_H
