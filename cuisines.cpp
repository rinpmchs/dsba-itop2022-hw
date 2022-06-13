#include "cuisines.h"
#include "ui_cuisines.h"

Cuisines::Cuisines(Dishes* dishes, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cuisines)
    , _model(new QStringListModel())
{
    ui->setupUi(this);
    QStringList L;
    for (const QString& string : dishes->getCuisines())
    {
        L.append(string);
    }
    _model->layoutAboutToBeChanged();
    _model->setStringList(L);
    ui->listView_cuisines->setModel(_model);
    _model->layoutChanged();
}

Cuisines::~Cuisines()
{
    delete ui;
}

void Cuisines::on_pushButton_close_clicked()
{
    close();
}




