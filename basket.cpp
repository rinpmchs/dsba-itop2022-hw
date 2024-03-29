#include "basket.h"
#include "ui_basket.h"

Basket::Basket(MyDataset* mydataset, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Basket)
    , _proxyModel(new MyFilterModel(this))
    , _mydataset{mydataset}
{
    ui->setupUi(this);

    _proxyModel->setSourceModel(mydataset);
    ui->tableView->setModel(_proxyModel);

    _proxyModel->layoutAboutToBeChanged();
    _proxyModel->setFilterKeyColumn(1);
//    _proxyModel->setFilterRegularExpression(QRegularExpression(
//    ui->search_input->text(), QRegularExpression::CaseInsensitiveOption));
//    _proxyModel->layoutChanged();
}

Basket::~Basket()
{
    delete ui;
}
