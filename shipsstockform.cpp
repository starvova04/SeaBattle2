#include "shipsstockform.h"
#include "shipform.h"
#include "ui_shipsstockform.h"

ShipsStockForm::ShipsStockForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShipsStockForm)
{
    setAcceptDrops(true);

    ui->setupUi(this);

    this->restoreShips();

}

void ShipsStockForm::restoreShips() {
    int sizeX = 4;
    int sizeY = 1;
    ShipForm* shipForm4 = new ShipForm(this, &sizeX, &sizeY);
    shipForm4->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->horizontalLayout->addWidget(shipForm4, 0, Qt::AlignLeft);

    sizeX = 3;
    for (int i = 0; i < 2; ++i) {
        ShipForm* shipForm = new ShipForm(this, &sizeX, &sizeY);
        shipForm->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->horizontalLayout_2->addWidget(shipForm, 0, Qt::AlignLeft);
    }
    sizeX = 2;
    for (int i = 0; i < 3; ++i) {
        ShipForm* shipForm = new ShipForm(this, &sizeX, &sizeY);
        shipForm->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->horizontalLayout_3->addWidget(shipForm, 0, Qt::AlignLeft);
    }

    sizeX = 1;
    for (int i = 0; i < 4; ++i) {
        ShipForm* shipForm = new ShipForm(this, &sizeX, &sizeY);
        shipForm->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->horizontalLayout_4->addWidget(shipForm, 0, Qt::AlignLeft);
    }
}

ShipsStockForm::~ShipsStockForm()
{
    delete ui;
}
