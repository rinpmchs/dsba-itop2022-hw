#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cuisines.h"
#include "dishes.h"
#include "diet.h"
#include "mydataset.h"
#include "datatablewindow.h"
#include "basket.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _dishes(new Dishes())//(this))
    , _mydataset(new MyDataset(_dishes, this))
{
    ui->setupUi(this);

    ui->tableView->setModel(_mydataset);
    ui->tableView->verticalHeader()->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_help_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("here's help");
    msgBox.exec();
}


void MainWindow::on_pushButton_cuisinesInfo_clicked()
{
//    Cuisines cuisines;
//    cuisines.exec();
    _cuisines = new Cuisines;
    _cuisines->show();
}


void MainWindow::on_pushButton_settings_clicked()
{
    _diet = new Diet;
    _diet->show();
}

void MainWindow::on_actionopen_file_triggered()
{
    QFile file = QFileDialog::getOpenFileName(
            this,
            "Open File",
            "",
            "Text files (*.csv);;All files (*.*)");

    _mydataset->layoutAboutToBeChanged();
    _dishes->loadFile(file);
//    ui->tableView->setModel(_mydataset);
    _mydataset->layoutChanged();
}

void MainWindow::on_pushButton_confirm_clicked()
{
    _basket = new Basket(_mydataset, this);
    _basket->show();
}
