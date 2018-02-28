#include "arrow.h"
#include "score.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <qmath.h>
#include "target.h"
#include <typeinfo>
#include <QDebug>

extern score * points;
arrow::arrow()
{
    QPixmap arro(":/images/a1.png");
    QPixmap scaled= arro.scaled(QSize(40,25));
    setPixmap(scaled);

    time=0;
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(75);
}

void arrow::move(){
    time += 0.3;
    // move arrow right
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(target)){
                target * t = dynamic_cast<target*>(colliding_items[i]);
                // remove them both
                //scene()->removeItem(colliding_items[i]);
                points-> increase();
                scene()->removeItem(this);
                // delete them both
                //delete colliding_items[i];
                if(t && t->a == 1)
                {
                    t->a = 0;
                    t->setRotation(0);
                }
                colliding_items[i]->setPos(400,540);
                delete this;
                return;
            }
        }

    presentAngle = qRadiansToDegrees(qAtan((75*qSin(qDegreesToRadians(-1*angle)) - 10*time)/(75*qCos(qDegreesToRadians(angle)))));
    setRotation(-1*presentAngle);
    double dy = 80 * qSin(qDegreesToRadians(-1*angle))*time-(5*(time*time));
    double dx = 80 * qCos(qDegreesToRadians(angle)) * time;
    setPos(initialX+dx,initialY-dy);
    if (pos().x() > 485)
    {
        scene()->removeItem(this);
        delete this;
    }
}
