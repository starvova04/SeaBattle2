#include "placeshipsform.h"
#include "ui_placeshipsform.h"

PlaceShipsForm::PlaceShipsForm(QWidget *parent, QStackedWidget* nav) :
    QWidget(parent),
    ui(new Ui::PlaceShipsForm)
{
    ui->setupUi(this);
    ui->widget_3->setAcceptDrops(true);
    this->_navigation = nav;

    this->ui->widget = new BattleField(this);
    this->ui->widget->setGeometry(20, 70, 280, 280);
    this->ui->widget->lower();
    this->ui->widget->show();

    ui->pushButton->setCursor(Qt::PointingHandCursor);
}
PlaceShipsForm::~PlaceShipsForm()
{
    delete ui;
}

void PlaceShipsForm::receiveData(bool newGame) {
    if (newGame) {
        delete this->ui->widget;
        this->ui->widget = new BattleField(this);
        this->ui->widget->setGeometry(20, 70, 280, 280);
        this->ui->widget->lower();
        this->ui->widget->show();

        QObjectList children = this->ui->widget_3->children();
        for (int i = 0; i < children.count(); i++) {
            delete children[i];
        }

        this->ui->widget_2->restoreShips();
    }
}

void PlaceShipsForm::on_pushButton_clicked()
{
    ShipsStockForm* stock = this->ui->widget_2;
    if (stock->children().count() == 1) {
        QObjectList children = this->ui->widget_3->children();
        for(QObject* child : children) {
            ShipForm* ship = dynamic_cast<ShipForm*>(child);
            QPoint posFromParent = ship->mapTo(this->ui->widget_3, QPoint(0, 0));
            int grid_i = posFromParent.y() / 28;
            int grid_j = posFromParent.x() / 28;

            BattleField* field = this->ui->widget;
            if (ship->isVertical) {
                for (int i = grid_i; i < grid_i + ship->height() / 28; ++i) {
                    CellBtn* btn = dynamic_cast<CellBtn*>(field->children()[i * 10 + grid_j + 1]);
                    btn->makeShip();
                }
            }
            else {
                for (int j = grid_j; j < grid_j + ship->width() / 28; ++j) {
                    CellBtn* btn = dynamic_cast<CellBtn*>(field->children()[grid_i * 10 + j + 1]);
                    btn->makeShip();
                }
            }

            field->enable(false);
        }
        this->sendDataToGameWidget();
        this->_navigation->setCurrentIndex(2);
    }
}

void PlaceShipsForm::sendDataToGameWidget() {
    qDebug() << this->ui->widget;
    emit dataPassed(this->ui->widget);
}
