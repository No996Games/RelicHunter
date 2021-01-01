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
#include <QDebug>


class LoadingScene{
public:
    QGraphicsScene scene;

    LoadingScene(QString *filenames){
        QPixmap image = QPixmap(*filenames);
        image = image.scaled(1440,900);
        QGraphicsPixmapItem *pic = scene.addPixmap(image);
        QGraphicsRectItem *rec = scene.addRect(0, 0, 100, 100);
        rec->setPos(0,0);
        pic->setPos(0,0);
        //scene.setSceneRect(0,0,1440,900);

        //qDebug()<<scene.height();
    }
};
#endif //RELICHUNTER_LOADINGSCENE_H












