#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cuisines.h"
#include "dishes.h"
#include "diet.h"
#include "mydataset.h"
#include "basket.h"
#include "favourites.h"
#include "about.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QFileDialog>
#include <QMenu>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    MyDataset* getMyDataset() { return _mydataset; }
    Favourites* getFavourites() { return _favourites; }

private slots:
    void on_pushButton_help_clicked();

    void on_pushButton_cuisinesInfo_clicked();

    void on_pushButton_settings_clicked();

    void on_actionopen_file_triggered();

    void on_pushButton_confirm_clicked();

    void addToFavourites();

    void deleteDish();

    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void on_table_favourites_customContextMenuRequested(const QPoint &pos);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_table_favourites_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

protected:
    Dishes* _dishes;
    MyDataset* _mydataset;
    Cuisines* _cuisines;
    Diet* _diet;
    Basket* _basket;
    QMenu* _menu;
    Favourites* _favourites;
    About* _about;
};
#endif // MAINWINDOW_H
