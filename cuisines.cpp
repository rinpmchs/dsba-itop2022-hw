#include "cuisines.h"
#include "ui_cuisines.h"

Cuisines::Cuisines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cuisines)
{
    ui->setupUi(this);
}

Cuisines::~Cuisines()
{
    delete ui;
}

void Cuisines::on_pushButton_close_clicked()
{
    close();
}




