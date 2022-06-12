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
    , _menu(new QMenu(this))
{
    ui->setupUi(this);

    ui->tableView->setModel(_mydataset);
    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    QAction* addToFavourites = new QAction("add to favourites", this);
//    QAction* deleteDish = new QAction("delete dish", this);
    connect(addToFavourites, SIGNAL(triggered()), this, SLOT(addToFavourites()));
//    connect(deleteDish, SIGNAL(triggered()), this, SLOT(deleteDish()));
    _menu->addAction(addToFavourites);
//    _menu->addAction(deleteDish);

    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this,
                SLOT(on_tableView_customContextMenuRequested(QPoint)));
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

void MainWindow::addToFavourites()
{
    QPoint p = ui->tableView->mapFromGlobal(QCursor::pos());
    size_t index = ui->tableView->indexAt(QPoint(p.x(), p.y())).row() - 1;
    _dishes->addToFavourites(index);
    // qDebug() << index;
}

//void MainWindow::editPlayer()
//{
//    size_t index = ui->tableView->selectionModel()->selectedRows().at(0).row();
//    size_t id = _storage->getPlayer(index).id;
//}

//void MainWindow::deleteDish()
//{
//    size_t index = ui->tableView->selectionModel()->selectedRows().at(0).row();
//    size_t id = _dishes->getDish(index).id;
//    _dishes->deleteDish(id);
//}

void MainWindow::on_tableView_customContextMenuRequested(const QPoint &pos)
{
    _menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

