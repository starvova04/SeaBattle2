#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include "battlefield.h"
#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class GamePage;
}

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = nullptr, QStackedWidget* nav = nullptr);
    ~GamePage();
signals:
    void dataPassed(bool newGame);
public slots:
    void receiveData(BattleField* fieldData);
    void sendDataForNewGame();
    void on_pushButton_clicked();
private:
    Ui::GamePage *ui;
public:
    BattleField* _battleField;
    BattleField* _botField;
    bool _playersMove;

    QStackedWidget* _navigation;

    void insertRandomShips();
    void addShip(int grid_i, int grid_j, int size, bool isVertical);

    bool checkPlayerField();
    bool checkBotField();

    void startGame();

    QPoint* generatePoint();
    bool checkPoint(QPoint* point);
    void atackPoint(QPoint* point);

    bool checkEdge(int grid_i, int grid_j, int width, int height, bool isVertical);
    bool checkAnotherShip(int grid_i, int grid_j, int width, int height, bool isVertical);
};

#endif // GAMEPAGE_H
