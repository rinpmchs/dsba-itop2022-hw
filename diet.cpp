#include "diet.h"
#include "ui_diet.h"

Diet::Diet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diet)
{
    ui->setupUi(this);
}

Diet::~Diet()
{
    delete ui;
}
