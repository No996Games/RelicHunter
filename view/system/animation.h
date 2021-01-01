//
// Created by yu qiu on 2/1/21.
//
#ifndef RELICHUNTER_ANIMATION_H
#define RELICHUNTER_ANIMATION_H

#include "../LoadingScene.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <vector>
#include <QGraphicsPixmapItem>

class animation{
    std::vector<QGraphicsPixmapItem*> pics;
    QGraphicsScene* s;
    int showing_pic;
    int xpos;
    int ypos;

public:
    animation(std::vector<QString> paths,int x, int y, QGraphicsScene* scene){
        xpos = x;
        ypos = y;
        showing_pic = 0;
        s=scene;

        for (int i = 0 ; i<paths.size() ; i ++){
            QPixmap pic = QPixmap(paths.at(i));
            QGraphicsPixmapItem* item= s->addPixmap(pic);
            item->setPos(x,y);
            pics.push_back(item);
            if(i!=0){
                item->hide();
            }
        }

    }

    void tick(){

        pics.at(showing_pic)->hide();
        showing_pic +=1;
        if(showing_pic == pics.size()){
            showing_pic = 0;
        }
        pics.at(showing_pic)->show();

    }
};


#endif //RELICHUNTER_ANIMATION_H
