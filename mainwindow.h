#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cuisines.h"
#include "dishes.h"
#include "diet.h"
#include "mydataset.h"
#include "basket.h"

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

private slots:
    void on_pushButton_help_clicked();

    void on_pushButton_cuisinesInfo_clicked();

    void on_pushButton_settings_clicked();

    void on_actionopen_file_triggered();

//    void onRemindersFileOpened();

    void on_pushButton_confirm_clicked();

    void addToFavourites();

    void on_tableView_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;

protected:
    Dishes* _dishes;
    MyDataset* _mydataset;
    Cuisines* _cuisines;
    Diet* _diet;
    Basket* _basket;
    QMenu* _menu;
//    QStringListModel* _model;
};
#endif // MAINWINDOW_H
