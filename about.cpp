#include "about.h"
#include "ui_about.h"

#include <QPainter>
#include <QHBoxLayout>


About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    updateConfigUi();
}

About::~About()
{
    delete ui;
}

void About::updateConfigUi()
{
    _logo = new Logo(this);
    QHBoxLayout* mainLayout = new QHBoxLayout(ui->widget);
    mainLayout->addWidget(_logo);
}
