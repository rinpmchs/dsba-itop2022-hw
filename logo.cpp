#include "logo.h"
#include <QPainter>

Logo::Logo(QWidget *parent)
    : QWidget{parent}
{

}

void Logo::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, true);

    QRadialGradient radialGrad(QPointF(10, 30), 50);
    radialGrad.setColorAt(0, QColor(133, 13, 29));
    radialGrad.setColorAt(0.5, QColor(239, 21, 104));
    radialGrad.setColorAt(1, Qt::blue);
    QBrush backBrush(radialGrad);
    painter.setBrush(backBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1 ));
}
