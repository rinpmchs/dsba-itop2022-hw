#ifndef BASKET_H
#define BASKET_H

#include "myfiltermodel.h"
#include "mydataset.h"

#include <QDialog>

namespace Ui {
class Basket;
}

class Basket : public QDialog
{
    Q_OBJECT

public:
    explicit Basket(MyDataset* mydataset, QWidget *parent = nullptr);
    ~Basket();

private:
    Ui::Basket *ui;

protected:
    MyFilterModel* _proxyModel;
    MyDataset* _mydataset;

};

#endif // BASKET_H
