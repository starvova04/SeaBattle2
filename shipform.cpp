#include "shipform.h"
#include "droparea.h"
#include "shippcellbtn.h"
#include "ui_shipform.h"

#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QPainter>

ShipForm::ShipForm(QWidget *parent, int* width, int* height, bool isVertical) :
    QWidget(parent),
    ui(new Ui::ShipForm)
{
    ui->setupUi(this);
    this->_width = width;
    this->_height = height;
    this->isVertical = isVertical;
    this->setFixedWidth(*width * 28);
    for (int i = 0; i < *width; ++i) {
        //CellBtn* cellBtn = new CellBtn(this, "#F8F275");
        ShippCellBtn* cellBtn = new ShippCellBtn(this, "#F8F275");
        cellBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cellBtn->setEnabled(false);

        this->_cells.append(cellBtn);

        this->ui->horizontalLayout->addWidget(cellBtn);
        this->disableChildMouseEvent(cellBtn);
    }


}

int* ShipForm::getWidth() {
    return this->_width;
}

int* ShipForm::getHeight() {
    return this->_height;
}

bool ShipForm::getOrientation() {
    return this->isVertical;
}


void ShipForm::disableChildMouseEvent(QWidget* childWidget) {
    childWidget->setAttribute(Qt::WA_TransparentForMouseEvents);
    QList<QWidget*> children = childWidget->findChildren<QWidget*>();
    for (QWidget* child : children) {
        this->disableChildMouseEvent(child);
    }
}

void ShipForm::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        this->isDragging = false;
        this->startPos = event->globalPosition();
    }

    QWidget::mousePressEvent(event);
}

void ShipForm::mouseMoveEvent(QMouseEvent* event) {
    QPointF diff = event->globalPosition() - this->startPos;
    if (!this->isDragging && diff.manhattanLength() > QApplication::startDragDistance()) {
        this->isDragging = true;
        QDrag* drag = new QDrag(this);
        QMimeData* mimeData = new QMimeData;
        mimeData->setData("application/custom-component", "Some data from press event");
        drag->setMimeData(mimeData);

        QPixmap pixmap(width(), height());
        pixmap.fill(Qt::transparent);

        QPainter painter(&pixmap);
        render(&painter);

        drag->setPixmap(pixmap);

        drag->exec();
    }
}

void ShipForm::mouseReleaseEvent(QMouseEvent* event) {
    if(!this->isDragging && event->button() == Qt::LeftButton && dynamic_cast<DropArea*>(this->parent())) {
        this->isVertical = this->isVertical ? false : true;

        QPointF p = event->position();
        QPointF posInParent = mapToParent(p);
        int x = posInParent.x();
        int y = posInParent.y();
        int grid_i = y / 28;
        int grid_j = x / 28;
        if (this->checkEdge(grid_i, grid_j, this->height() / 28, this->width() / 28, this->isVertical) &&
            this->checkAnotherShip(grid_i, grid_j, this->height() / 28, this->width() / 28, this->isVertical)) {
            int tmpWidth = this->width();
            this->setFixedWidth(this->height());
            this->setFixedHeight(tmpWidth);
            QLayout* current = this->layout();
            if (current)
                delete current;

            if (this->isVertical) {
                QVBoxLayout* newLayout = new QVBoxLayout(this);
                newLayout->setContentsMargins(0, 0, 0, 0);
                newLayout->setSpacing(0);
                for (int i = 0; i < this->_cells.count(); ++i) {
                    newLayout->addWidget(this->_cells[i]);
                }
                this->setLayout(newLayout);

                this->children();
            }
            else {
                QHBoxLayout* newLayout = new QHBoxLayout(this);
                newLayout->setContentsMargins(0, 0, 0, 0);
                newLayout->setSpacing(0);
                for (int i = 0; i < this->_cells.count(); ++i) {
                    newLayout->addWidget(this->_cells[i]);
                }
                this->setLayout(newLayout);
            }


        }
        else {
            this->isVertical = this->isVertical ? false : true;
        }
    }
    this->isDragging = false;
    QWidget::mouseReleaseEvent(event);
}

bool ShipForm::checkEdge(int grid_i, int grid_j, int width, int height, bool isVertical) {
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
bool ShipForm::checkAnotherShip(int grid_i, int grid_j, int width, int height, bool isVertical){
    QWidget* first_prnt = dynamic_cast<QWidget*>(this->parent());
    QWidget* second_prnt = dynamic_cast<QWidget*>(this->parent()->parent());
    this->setParent(nullptr);
    QObjectList chhh = second_prnt->children();
    QObjectList children = chhh[5]->children();
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
                        if (widgetRectFromParent.contains(*point)) {
                            this->setParent(first_prnt);
                            this->show();
                            return false;
                        }
                    }
                    else continue;
                }
                delete point;

            }
        }
    }
    this->setParent(first_prnt);
    this->show();
    return true;
}

void ShipForm::enterEvent(QEvent* event) {
    this->setMouseTracking(true);
}
void ShipForm::leaveEvent(QEvent* event) {
    this->setMouseTracking(false);
}
ShipForm::~ShipForm()
{
    delete ui;
}
