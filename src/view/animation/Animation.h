//
// Created by Yuchen Shen on 2/1/21.
//

#ifndef RELICHUNTER_ANIMATION_H
#define RELICHUNTER_ANIMATION_H
#include <vector>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
class Animation {
private:
    std::vector<QGraphicsPixmapItem*>* pics = nullptr;
    QGraphicsScene* scene = nullptr;
    int showingPic = 0;
    int xpos = 0;
    int ypos = 0;
    int width = 0;
    int height = 0;
public:
    Animation(std::vector<QString> paths, int x, int y,int w,int h, QGraphicsScene* scene){
        xpos = x;
        ypos = y;
        width = w;
        height = h;
        pics = new std::vector<QGraphicsPixmapItem*>();

        this->scene = scene;
        for (int i = 0 ; i<paths.size() ; i ++){
            QPixmap pic = QPixmap(paths.at(i));

            pic = pic.scaled(width,height);

            QGraphicsPixmapItem* item= this->scene->addPixmap(pic);

            item->setPos(x,y);

            pics->push_back(item);
            if(i!=0){
                item->hide();
            }

        }
    }
    void tick(){

        if(pics!=nullptr){
            pics->at(showingPic)->hide();
            showingPic+=1;
            if(showingPic == pics->size()){
                showingPic = 0;
            }
            pics->at(showingPic)->show();

        }


    }
};


#endif //RELICHUNTER_ANIMATION_H
