//
// Created by Yuchen Shen on 30/12/20.
//

#ifndef RELICHUNTER_LOADINGSCENE_H
#define RELICHUNTER_LOADINGSCENE_H
#include <QGraphicsScene>
#include <QPixmap>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <Qdebug>
#include <QBrush>
#include "BasicScene.h"
#include <vector>
#include "animation/Animation.h"
class LoadingScene : BasicScene{
private:
    Animation* gear;

public:
    LoadingScene(QGraphicsView* view, QString *filenames);
    void tick(int frameCount);
};


LoadingScene::LoadingScene(QGraphicsView *view, QString *filenames) : BasicScene(view)
{
    QPixmap image = QPixmap(*filenames);
    image = image.scaled(view->size().width(),view->size().height());
    QGraphicsPixmapItem *pic = scene.addPixmap(image);

    QGraphicsRectItem *rec = scene.addRect(0, view->size().height()/4 *3, view->size().width(), view->size().height()/4);
    rec->setBrush(QBrush(QColor(0,0,0,200)));
    pic->setPos(0,0);

    QString gear_path1 = ":resources/pic/LoadingGear1.png";
    QString gear_path2 = ":resources/pic/LoadingGear2.png";
    std::vector<QString> paths;
    paths.push_back(gear_path1);
    paths.push_back(gear_path2);
    Animation gear(paths,scene.width()-200,scene.height()-200,&scene);
    this->gear = &gear;


}


void LoadingScene::tick(int frameCount) {
    //qDebug()<<"this is here";
    //gear->tick();
}


#endif //RELICHUNTER_LOADINGSCENE_H












