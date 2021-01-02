//
// Created by Yuchen Shen on 2/1/21.
//

#ifndef RELICHUNTER_BASICSCENE_H
#define RELICHUNTER_BASICSCENE_H
#include <iostream>
#include <QTimeLine>
#include <QGraphicsView>
#include <QGraphicsScene>
class BasicScene : QObject{
    Q_OBJECT

public:
    BasicScene(QGraphicsView* view){
        this->view = view;
        startRun();
    }
    QGraphicsScene* getScene(){
        return &scene;
    }

protected slots:
    virtual void tick(int frameCount) = 0;

protected:
    QGraphicsScene scene;
    QGraphicsView* view;
private:
    void startRun(){
        QTimeLine *timeLine = new QTimeLine(1000);
        timeLine->setFrameRange(0, 120);
        timeLine->setLoopCount(0);
        //connect(timeLine,&QTimeLine::frameChanged, this, &WindowController::tick);
        connect(timeLine,SIGNAL(frameChanged(int)), this, SLOT(tick(int)));
        timeLine->start();
    }
};
#endif //RELICHUNTER_BASICSCENE_H
