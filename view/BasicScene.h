//
// Created by Yuchen Shen on 2/1/21.
//

#ifndef RELICHUNTER_BASICSCENE_H
#define RELICHUNTER_BASICSCENE_H
#include <iostream>
class BasicScene : QObject{
public:
    BasicScene(QGraphicsView* view){
        this->view = view;
    }
    QGraphicsScene* getScene(){
        return &scene;
    }
    virtual void tick(int frameCount) = 0;
protected:
    QGraphicsScene scene;
    QGraphicsView* view;
};
#endif //RELICHUNTER_BASICSCENE_H
