#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsPixmapItem>

#include <QObject>
class target: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    target();
public slots:
    void move();

};
#endif // TARGET_H