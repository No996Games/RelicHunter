//
// Created by Yuchen Shen on 2/1/21.
//

#ifndef RELICHUNTER_ANIMATION_H
#define RELICHUNTER_ANIMATION_H
#include <vector>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
class Animation {
private:
    std::vector<QGraphicsPixmapItem*> pics;
    QGraphicsScene* scene;
    int showingPic;
    int xpos;
    int ypos;
public:
    Animation(std::vector<QString> paths, int x, int y, QGraphicsScene* scene){
        xpos = x;
        ypos = y;
        showingPic = 0;
        this->scene = scene;
        for (int i = 0 ; i<paths.size() ; i ++){
            QPixmap pic = QPixmap(paths.at(i));
            QGraphicsPixmapItem* item= this->scene->addPixmap(pic);
            item->setPos(x,y);
            pics.push_back(item);
            if(i!=0){
                item->hide();
            }
        }
    }
    void tick(){
        pics.at(showingPic)->hide();
        showingPic +=1;
        if(showingPic == pics.size()){
            showingPic = 0;
        }
        pics.at(showingPic)->show();
    }
};


#endif //RELICHUNTER_ANIMATION_H
