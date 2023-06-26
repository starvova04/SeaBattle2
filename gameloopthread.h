#ifndef GAMELOOPTHREAD_H
#define GAMELOOPTHREAD_H

#include "gamepage.h"
#include <QObject>
#include <QThread>
class GameLoopThread : public QThread
{
    Q_OBJECT
public:
    explicit GameLoopThread(QObject *parent = nullptr, GamePage* gamePage = nullptr);

    void run() override;
signals:
    void finishedGame();
private:
    GamePage* gamePage;
signals:

};

#endif // GAMELOOPTHREAD_H
