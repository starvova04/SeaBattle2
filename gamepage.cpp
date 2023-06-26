#include "gamepage.h"
#include "cellbtn.h"
#include "gameloopthread.h"
#include "ui_gamepage.h"

#include <QRandomGenerator>
#include <QLabel>

GamePage::GamePage(QWidget *parent, QStackedWidget* nav) :
    QWidget(parent),
    ui(new Ui::GamePage)
{
    ui->setupUi(this);

    this->_navigation = nav;

    this->setAttribute(Qt::WA_TranslucentBackground);

    ui->label->setVisible(false);
    ui->pushButton->setVisible(true);

    ui->pushButton->setCursor(Qt::PointingHandCursor);

    CellBtn* shipBtn = new CellBtn(this);
    shipBtn->makeShip();
    shipBtn->setGeometry(20, 370, 30, 30);
    shipBtn->show();
    shipBtn->setEnabled(false);

    QLabel* shipLbl = new QLabel("Ship", this);
    shipLbl->setGeometry(60, 370, 100, 30);


    CellBtn* missedBtn = new CellBtn(this);
    missedBtn->makeMissed();
    missedBtn->setGeometry(20, 400, 30, 30);
    missedBtn->show();
    missedBtn->setEnabled(false);

    QLabel* missedLbl = new QLabel("Missed", this);
    missedLbl->setGeometry(60, 400, 100, 30);

    CellBtn* killedBtn = new CellBtn(this);
    killedBtn->makeKilled();
    killedBtn->setGeometry(20, 430, 30, 30);
    killedBtn->show();
    killedBtn->setEnabled(false);

    QLabel* killedLbl = new QLabel("Killed", this);
    killedLbl->setGeometry(60, 430, 100, 30);



    this->_playersMove = true;
}

void GamePage::receiveData(BattleField* fieldData) {

    this->_botField = new BattleField(this);
    this->_botField->setFixedWidth(280);
    this->_botField->setFixedHeight(280);
    this->_botField->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->horizontalLayout->addWidget(this->_botField);

    this->insertRandomShips();

    this->_playersMove = true;

    this->_battleField = new BattleField(this, fieldData);
    qDebug() << this->_battleField;
    this->_battleField->setFixedWidth(280);
    this->_battleField->setFixedHeight(280);
    this->_battleField->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->ui->horizontalLayout->insertWidget(0, this->_battleField);

    this->_botField->enable(true);

    this->ui->label->setVisible(false);
    this->ui->pushButton->setVisible(false);

    GameLoopThread* gameLoop = new GameLoopThread(this, this);
    connect(gameLoop, &GameLoopThread::finishedGame, [this](){
        this->_botField->enable(false);

        bool isWinner = this->checkPlayerField()?true:false;
        this->ui->label->setText(QString::fromStdString(isWinner?"Winner":"Loser"));
        this->ui->label->setStyleSheet(QString::fromStdString(isWinner?"QLabel { background: rgba(81, 243, 126, 160);  border: 2px solid #1FA3AB; border-radius: 5px; font-size: 40px;}":
                                                                  "QLabel { background: rgba(232, 78, 78, 160);  border: 2px solid #1FA3AB; border-radius: 5px; font-size: 40px;}"));
        this->ui->label->setVisible(true);
        this->ui->pushButton->setVisible(true);
        qDebug() << "Finished game";
    });
    gameLoop->start();
}

void GamePage::sendDataForNewGame() {
    delete this->_botField;
    delete this->_battleField;
    emit dataPassed(true);
}

void GamePage::startGame() {
    while (true) {
        if (this->_playersMove) {
            this->_botField->enable(true);
            if(this->_botField->lastPressed != nullptr)
                while(this->_botField->lastPressed->isKilled) {}
            this->_botField->lastPressed->isKilled = true;
            this->_playersMove = false;
        }
        else {
            this->_botField->enable(false);
            do {
                QPoint* point;
                do {
                    point = this->generatePoint();
                    qDebug() << "Gen new point " << *point;
                }
                while(!this->checkPoint(point));
                this->atackPoint(point);

                delete point;
            }
            while(this->_battleField->lastPressed->isKilled);
            this->_playersMove = true;
        }
    }
}

bool GamePage::checkPlayerField() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            CellBtn* btn = dynamic_cast<CellBtn*>(this->_battleField->children()[i * 10 + j + 1]);
            if (btn->isShip) return true;
        }
    }
    return false;
}

bool GamePage::checkBotField() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            CellBtn* btn = dynamic_cast<CellBtn*>(this->_botField->children()[i * 10 + j + 1]);
            if (btn->isShip) return true;
        }
    }
    return false;
}

QPoint* GamePage::generatePoint() {
    srand(time(0));
    int x = QRandomGenerator::global()->bounded(10);
    int y = QRandomGenerator::global()->bounded(10);
    qDebug() << "rand x, y " << x << " " << y;
    return (new QPoint(x, y));
}

bool GamePage::checkPoint(QPoint* point) {
    QObjectList children = this->_battleField->children();
    CellBtn* cellBtn = dynamic_cast<CellBtn*>(children[point->y() * 10 + point->x() + 1]);
    if(!cellBtn->isKilled && !cellBtn->isMissed)
        return true;
    else return false;
}

void GamePage::atackPoint(QPoint* point) {
    CellBtn* cellBtn = dynamic_cast<CellBtn*>(this->_battleField->children()[point->y() * 10 + point->x() + 1]);
    if (cellBtn->isShip)
        cellBtn->makeKilled();
    else
        cellBtn->makeMissed();
    this->_battleField->lastPressed = cellBtn;
}

void GamePage::insertRandomShips() {
    srand(time(0));


    // --- 4 cell ship ---

    qDebug() << "4 cell";

    bool isVertical = rand() % 2;

    int size = 4;

    int grid_i;
    int grid_j;

    do {
        grid_i = rand() % 10;
        grid_j = rand() % 10;
        qDebug() << grid_i << " - "<< grid_j << " - " << isVertical;
    } while (!(this->checkEdge(grid_i, grid_j, isVertical?1:size, isVertical?size:1, isVertical) &&
               this->checkAnotherShip(grid_i, grid_j, isVertical?1:size, isVertical?size:1, isVertical)));

    this->addShip(grid_i, grid_j, size, isVertical);


    // --- 3 cell ship ---

    qDebug() << "3 cell";

    for (int i = 0; i < 2; ++i) {
        isVertical = rand() % 2;
        size = 3;
        do {
            grid_i = rand() % 10;
            grid_j = rand() % 10;
            qDebug() << grid_i << " - "<< grid_j << " - " << isVertical;
        } while (!(this->checkEdge(grid_i, grid_j, isVertical?1:size, isVertical?size:1, isVertical) &&
                   this->checkAnotherShip(grid_i, grid_j, isVertical?1:size, isVertical?size:1, isVertical)));
        this->addShip(grid_i, grid_j, size, isVertical);
    }


    // --- 2 cell ship ---

    qDebug() << "2 cell";

    for (int i = 0; i < 3; ++i) {
        isVertical = rand() % 2;
        size = 2;
        do {
            grid_i = rand() % 10;
            grid_j = rand() % 10;
            qDebug() << grid_i << " - "<< grid_j << " - " << isVertical;
        } while (!(this->checkEdge(grid_i, grid_j, isVertical?1:size, isVertical?size:1, isVertical) &&
                   this->checkAnotherShip(grid_i, grid_j, isVertical?1:size, isVertical?size:1, isVertical)));
        this->addShip(grid_i, grid_j, size, isVertical);
    }


    // --- 1 cell ship ---

    qDebug() << "1 cell";

    for (int i = 0; i < 4; ++i) {
        isVertical = rand() % 2;
        size = 1;
        do {
            grid_i = rand() % 10;
            grid_j = rand() % 10;
            qDebug() << grid_i << " - "<< grid_j << " - " << isVertical;
        } while (!(this->checkEdge(grid_i, grid_j, isVertical?1:size, isVertical?size:1, isVertical) &&
                   this->checkAnotherShip(grid_i, grid_j, isVertical?1:size, isVertical?size:1, isVertical)));
        this->addShip(grid_i, grid_j, size, isVertical);
    }

}

void GamePage::addShip(int grid_i, int grid_j, int size, bool isVertical) {
    qDebug() << "Added " << size << "cells ship";
    if (!isVertical) {
        for (int j = grid_j; j < grid_j + size; ++j) {
            CellBtn* btn = dynamic_cast<CellBtn*>(this->_botField->children()[grid_i * 10 + j + 1]);
            btn->isShip = true;
        }
    }
    else {
        for (int i = grid_i; i < grid_i + size; ++i) {
            CellBtn* btn = dynamic_cast<CellBtn*>(this->_botField->children()[i * 10 + grid_j + 1]);
            btn->isShip = true;
        }
    }
}

bool GamePage::checkEdge(int grid_i, int grid_j, int width, int height, bool isVertical) {
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

bool GamePage::checkAnotherShip(int grid_i, int grid_j, int width, int height, bool isVertical){


    BattleField* prnt = this->_botField;
    QObjectList children = prnt->children();

    if (dynamic_cast<CellBtn*>(children[grid_i * 10 + grid_j + 1])->isShip)
        return false;

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
                if (i < 10 && j < 10 && i > -1 && j > -1) {
                    CellBtn* cell = dynamic_cast<CellBtn*>(children[i * 10 + j + 1]);

                    if (cell->isShip)
                        return false;
                }
            }
        }
    }
    return true;
}


GamePage::~GamePage()
{
    delete ui;
}

void GamePage::on_pushButton_clicked()
{
    this->sendDataForNewGame();
    this->_navigation->setCurrentIndex(1);
}

