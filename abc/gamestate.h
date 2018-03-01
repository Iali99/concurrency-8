#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QGraphicsScene>
#include <QPointF>
//#include "myplayer1.h"
#include "target.h"
class myplayer1;
class gamestate
{
public:
    gamestate(QGraphicsScene * scene);
    QGraphicsScene * stateScene;
    QPointF Player1Position;
    QPointF Player2Position;
    QPointF TargetPosition;
    bool isArrow1; //tells if arrow of player1 is in the scene.
    bool isArrow2; //tells if arrow of player2 is in the scene.
    QPointF Arrow1Position;
    qreal Arrow1Angle;
    qreal Arrow2Angle;
    QPointF Arrow2Position;
    qreal Bow1Angle;
    qreal Bow2Angle;

    void StateSet(myplayer1* p1 , myplayer1 * p2,target * t);
};
#endif // GAMESTATE_H
