#ifndef LOGO_H
#define LOGO_H

#include <QWidget>

class Logo : public QWidget
{
    Q_OBJECT
public:
    explicit Logo(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

signals:

};

#endif // LOGO_H

//#ifndef LOGO_H
//#define LOGO_H

//#include <QObject>
//#include <QPainter>
//#include <QPaintEvent>

//class Logo : public QObject
//{
//    Q_OBJECT
//public:
//    explicit Logo(QWidget *parent = nullptr);
//    ~Logo();

//protected:
//    // override paintEvent function for implementing custom drawing and painting
//    void paintEvent(QPaintEvent *event) override;

//signals:

//};

//#endif // LOGO_H

