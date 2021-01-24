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
#include <QBrush>
#include "BasicScene.h"
#include <vector>
#include "src/view/animation/Animation.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>
class LoadingScene : BasicScene{
private:
    Animation* gear;
    QGraphicsTextItem* tip;
protected slots:
    void tick(int frameCount);
public:
    LoadingScene(QGraphicsView* view, QString *filenames);

};


LoadingScene::LoadingScene(QGraphicsView *view, QString *filenames) : BasicScene(view)
{
    QPixmap image = QPixmap(*filenames);
    image = image.scaled(view->size().width(),view->size().height());
    QGraphicsPixmapItem *pic = scene.addPixmap(image);

    QGraphicsRectItem *rec = scene.addRect(0, view->size().height()/4 *3, view->size().width(), view->size().height()/4);
    rec->setBrush(QBrush(QColor(0,0,0,200)));
    pic->setPos(0,0);

    double ratio = scene.height()/scene.width();

    gear = new Animation(":resources/pic/LoadingGear",".png",4,scene.width()-(scene.width()*0.1*ratio),scene.height()-scene.height()*0.1,scene.width()*0.1*ratio,scene.height()*0.1,&scene);
    tip = scene.addText("Loading...");


    tip->setScale(2);
    QRectF f = tip->boundingRect();

    tip->setPos(scene.width()-(scene.width()*0.1*ratio)-f.width()*2,scene.height()-f.height()*2);
    tip->setDefaultTextColor(Qt::white);
    tip->setFont(QFont("Times"));
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:resources/sound/music/189BeatThee.mp3"));

    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->setVolume(50);
    music->play();
    startRun();

}

void LoadingScene::tick(int frameCount) {
    //qDebug()<<"this is here";
    this->gear->tick();

}

#endif //RELICHUNTER_LOADINGSCENE_H












