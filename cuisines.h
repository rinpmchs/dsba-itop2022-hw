#ifndef CUISINES_H
#define CUISINES_H

#include <QDialog>
#include <QStringListModel>
#include "dishes.h"

namespace Ui {
class Cuisines;
}

class Cuisines : public QDialog
{
    Q_OBJECT

public:
    explicit Cuisines(Dishes* dishes, QWidget *parent = nullptr);
    ~Cuisines();

private slots:
    void on_pushButton_close_clicked();

private:
    Ui::Cuisines *ui;
    QStringListModel* _model;
};

#endif // CUISINES_H
