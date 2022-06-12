#include "datatablewindow.h"
#include "ui_datatablewindow.h"
#include "cuisines.h"
#include "dishes.h"
#include "diet.h"
#include "mydataset.h"

DataTableWindow::DataTableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataTableWindow)
//  , _dishes(new Dishes(this))
//  , _mydataset(new MyDataset(_dishes, this))

{
    ui->setupUi(this);

//    ui->tableView->setModel(_mydataset);
}

DataTableWindow::~DataTableWindow()
{
    delete ui;
}
