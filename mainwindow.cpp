#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "datatablewindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _dishes(new Dishes())//(this))
    , _mydataset(new MyDataset(_dishes, this))
    , _menu(new QMenu(this))
    , _favourites(new Favourites(_dishes, this))
{
    ui->setupUi(this);

    ui->tableView->setModel(_mydataset);
    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    QAction* addToFavourites = new QAction("add to favourites", this);
    connect(addToFavourites, SIGNAL(triggered()), this, SLOT(addToFavourites()));
    _menu->addAction(addToFavourites);

    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this,
                SLOT(on_tableView_customContextMenuRequested(QPoint)));



    ui->table_favourites->setModel(_favourites);
    ui->table_favourites->verticalHeader()->setVisible(false);
    ui->table_favourites->horizontalHeader()->setVisible(false);

    ui->table_favourites->setContextMenuPolicy(Qt::CustomContextMenu);
    QAction* deleteDish = new QAction("delete from favourites", this);
    connect(deleteDish, SIGNAL(triggered()), this, SLOT(deleteDish()));
    _menu->addAction(deleteDish);

    connect(ui->table_favourites, SIGNAL(customContextMenuRequested(QPoint)), this,
                SLOT(on_table_favourites_customContextMenuRequested(QPoint)));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_help_clicked()
{
    _about = new About;
    _about->show();
}


void MainWindow::on_pushButton_cuisinesInfo_clicked()
{
//    Cuisines cuisines;
//    cuisines.exec();
    _cuisines = new Cuisines(_dishes);
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
    _mydataset->layoutChanged();
}

void MainWindow::on_pushButton_confirm_clicked()
{
    _basket = new Basket(_mydataset, this);
    _basket->show();
}

void MainWindow::addToFavourites()
{
    _favourites->layoutAboutToBeChanged();
    int selected = ui->tableView->currentIndex().row();
    _dishes->addToFavourites(selected);
    _favourites->layoutChanged();
}

void MainWindow::deleteDish()
{
    int selected = ui->table_favourites->currentIndex().row();
    _favourites->layoutAboutToBeChanged();
    _dishes->deleteFromFavourites(selected);
    _favourites->layoutChanged();
}

void MainWindow::on_tableView_customContextMenuRequested(const QPoint &pos)
{
    _menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

void MainWindow::on_table_favourites_customContextMenuRequested(const QPoint &pos)
{
    _menu->popup(ui->table_favourites->viewport()->mapToGlobal(pos));
}


void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    _favourites->layoutAboutToBeChanged();
    _dishes->addToFavourites(row);
    _favourites->layoutChanged();
}


void MainWindow::on_table_favourites_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    _favourites->layoutAboutToBeChanged();
    _dishes->deleteFromFavourites(row);
    _favourites->layoutChanged();
}
