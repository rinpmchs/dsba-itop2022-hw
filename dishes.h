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
//    void deleteDish(QString);
    QVariant getFavourites(const QModelIndex& index);

protected:
//    QList<Dish>* _dishes;
    QStringList _headers = {}; //QList<QVariant>
    QList<QList<QVariant>> _storage; // QList<QStringList>
    QList<QList<QVariant>> _favourites;

};

#endif // DISHES_H
