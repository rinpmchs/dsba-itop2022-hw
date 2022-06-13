#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

#include "logo.h"

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

protected:
    void updateConfigUi();

private:
    Ui::About *ui;
    Logo* _logo;
};

#endif // ABOUT_H


//#ifndef ABOUT_H
//#define ABOUT_H


//#include <QDialog>
//#include <QHBoxLayout>

//#include "logo.h"

//namespace Ui {
//class About;
//}

//class About : public QDialog
//{
//    Q_OBJECT

//public:
//    explicit About(QWidget *parent = nullptr);
//    ~About();

//private:
//    Ui::About *ui;

//protected:
//    void paintEvent(QPaintEvent* event);

//private:
//    void customizeUi();

//protected:
//    Logo* _logo;
//};


//#endif // ABOUT_H
