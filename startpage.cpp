#include "startpage.h"
#include "ui_startpage.h"
#include <QStackedWidget>

StartPage::StartPage(QWidget *parent, QStackedWidget* nav) :
    QWidget(parent),
    ui(new Ui::StartPage)
{
    ui->setupUi(this);
    this->_navigation = nav;
    ui->pushButton->setCursor(Qt::PointingHandCursor);
}

StartPage::~StartPage()
{
    delete ui;
}

void StartPage::on_pushButton_clicked()
{
    this->_navigation->setCurrentIndex(1);
}

