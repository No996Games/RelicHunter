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
class LoadingScene : BasicScene{

public:
    LoadingScene(QGraphicsView* view, QString *filenames);
};

LoadingScene::LoadingScene(QGraphicsView *view, QString *filenames) : BasicScene(view)
{
    QPixmap image = QPixmap(*filenames);

    QString path = ":resources/pic/LoadingGear1.png";
    QPixmap gear = QPixmap(path);

    qDebug()<< gear.isNull();

    image = image.scaled(view->size().width(),view->size().height());
    QGraphicsPixmapItem *pic = scene.addPixmap(image);


    QGraphicsPixmapItem *g = scene.addPixmap(gear);
    

    QGraphicsRectItem *rec = scene.addRect(0, view->size().height()/4 *3, view->size().width(), view->size().height()/4);
    rec->setBrush(QBrush(QColor(0,0,0,200)));
    pic->setPos(0,0);

    g->setPos(100,100);
}

#endif //RELICHUNTER_LOADINGSCENE_H












