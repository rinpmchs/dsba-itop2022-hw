#ifndef DIET_H
#define DIET_H

#include <QDialog>

namespace Ui {
class Diet;
}

class Diet : public QDialog
{
    Q_OBJECT

public:
    explicit Diet(QWidget *parent = nullptr);
    ~Diet();

private:
    Ui::Diet *ui;
};

#endif // DIET_H
