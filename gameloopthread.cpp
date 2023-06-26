#include "gameloopthread.h"
#include "qapplication.h"
#include <QTimer>

GameLoopThread::GameLoopThread(QObject *parent, GamePage* gamePage)
    : QThread(parent)
{
    this->gamePage = gamePage;
}


void GameLoopThread::run() {
    while (!isInterruptionRequested() && this->gamePage->checkBotField() && this->gamePage->checkPlayerField()) {
        if (this->gamePage->_playersMove) {
            this->gamePage->_botField->enable(true);
            if(this->gamePage->_botField->lastPressed != nullptr)
                while(this->gamePage->_botField->lastPressed->isKilled) {
                    if (!this->gamePage->checkBotField()) break;
                }
            this->gamePage->_botField->lastPressed->isKilled = true;
            this->gamePage->_playersMove = false;
        }
        else {
            this->gamePage->_botField->enable(false);
            do {
                QPoint* point;
                do {
                    point = this->gamePage->generatePoint();
                    qDebug() << "Gen new point " << *point;
                }
                while(!this->gamePage->checkPoint(point));
                this->gamePage->atackPoint(point);
                delete point;
                if (!this->gamePage->checkPlayerField()) break;
            }
            while(this->gamePage->_battleField->lastPressed->isKilled);
            this->gamePage->_playersMove = true;
        }
    }
    emit finishedGame();
}
