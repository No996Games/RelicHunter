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
#include "BasicScene.h"
class LoadingScene : BasicScene{

public:
    LoadingScene(QGraphicsView* view, QString *filenames);
};

LoadingScene::LoadingScene(QGraphicsView *view, QString *filenames) : BasicScene(view)
{
    qDebug()<<"bbb";
    QPixmap image = QPixmap(*filenames);

    image = image.scaled(1440,900);
    //qDebug()<<"bbb";
    QGraphicsPixmapItem *pic = scene.addPixmap(image);
    //qDebug()<<"ccc";
    QGraphicsRectItem *rec = scene.addRect(0, 0, 100, 100);
    rec->setPos(0,0);
    pic->setPos(0,0);
}

#endif //RELICHUNTER_LOADINGSCENE_H












