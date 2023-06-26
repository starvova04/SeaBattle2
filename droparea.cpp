#include "droparea.h"
#include <QHBoxLayout>
#include "qobjectdefs.h"
#include "ui_droparea.h"

DropArea::DropArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropArea)
{
    ui->setupUi(this);

    setAcceptDrops(true);
}

void DropArea::dragEnterEvent(QDragEnterEvent* event) {
    if(event->mimeData()->hasFormat("application/custom-component")) {
        event->acceptProposedAction();
    }
}



void DropArea::dropEvent(QDropEvent* event) {
    if(event->mimeData()->hasFormat("application/custom-component")) {
        event->acceptProposedAction();
        ShipForm* senderShip = qobject_cast<ShipForm*>(event->source());

        QPointF p = event->position();
        int x = p.x();
        int y = p.y();
        int grid_i = y / 28;
        int grid_j = x / 28;

        if (this->checkEdge(grid_i, grid_j, senderShip->width() / 28, senderShip->height() / 28, senderShip->isVertical) &&
            this->checkAnotherShip(grid_i, grid_j, senderShip->width() / 28, senderShip->height() / 28, senderShip->isVertical)) {
            senderShip->setParent(this);
            senderShip->move(grid_j * 28, grid_i * 28);

            senderShip->show();
        }

    }
}

void DropArea::dragMoveEvent(QDragMoveEvent* event) {
    if(event->mimeData()->hasFormat("application/custom-component")) {
        event->acceptProposedAction();
        ShipForm* senderShip = qobject_cast<ShipForm*>(event->source());

        QPointF p = event->position();
        int x = p.x();
        int y = p.y();
        int grid_i = y / 28;
        int grid_j = x / 28;

        int last_x = -1, last_y = -1;
        if (this->children().contains(senderShip)) {
            last_x = senderShip->mapTo(this, QPoint(0, 0)).x();
            last_y = senderShip->mapTo(this, QPoint(0, 0)).y();
        }
        if (this->children().contains(senderShip))
            senderShip->setParent(nullptr);


        if(this->checkEdge(grid_i, grid_j, senderShip->width() / 28, senderShip->height() / 28, senderShip->isVertical) &&
            this->checkAnotherShip(grid_i, grid_j, senderShip->width() / 28, senderShip->height() / 28, senderShip->isVertical)) {
            senderShip->setParent(this);

            senderShip->move(grid_j * 28, grid_i * 28);

            senderShip->show();
        }
        else if (last_x != -1 && last_y != -1){
            senderShip->setParent(this);
            senderShip->move(last_x, last_y);
            senderShip->show();
        }
    }
}

bool DropArea::checkEdge(int grid_i, int grid_j, int width, int height, bool isVertical) {
    if (isVertical) {
        if (10 * 28 - grid_i * 28 < height * 28)
            return false;
    }
    else {
        if(10 * 28 - grid_j * 28 < width * 28)
            return false;
    }
    return true;
}
bool DropArea::checkAnotherShip(int grid_i, int grid_j, int width, int height, bool isVertical){
    QObjectList children = this->children();
    int endCellIndexI = grid_i + 1;
    int endCellIndexJ = grid_j + width;

    if(isVertical) {
        endCellIndexI = grid_i + height;
        endCellIndexJ = grid_j + 1;
    }

    for (int i = grid_i - 1; i <= endCellIndexI; i++) {
        for (int j = grid_j - 1; j <= endCellIndexJ; j++) {
            if (i == grid_i && j == grid_j && !isVertical)
                j += width - 1;
            if (j == grid_j && i != grid_i - 1 && i != endCellIndexI && isVertical)
                continue;
            else {
                QPoint* point = new QPoint(j * 28 + 14, i * 28 + 14);
                for (int k = 0; k < children.count(); k++) {
                    ShipForm* ship = dynamic_cast<ShipForm*>(children[k]);
                    if (ship)
                    {
                        QRect widgetRect = ship->rect();

                        QPoint widgetStartFromParent = ship->mapToParent(*(new QPoint(widgetRect.x(), widgetRect.y())));

                        QRect widgetRectFromParent(widgetStartFromParent, widgetRect.size());
                        if (widgetRectFromParent.contains(*point))
                            return false;
                    }
                    else continue;
                }
                delete point;

            }
        }
    }
    return true;
}
DropArea::~DropArea()
{
    delete ui;
}
