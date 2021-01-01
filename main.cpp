#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "GUI/LoadingScene.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
int WIDTH;
int HEIGHT;

void init(QGraphicsView * w){
    //w->setWindowFlags(Qt::FramelessWindowHint);
    w->setWindowFlags(Qt::Window);
    w->setWindowTitle("RelicHunter");
    w->showFullScreen();
    w->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    w->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    w->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

}
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString path = ":/resources/pic/city.png";

    LoadingScene scene(&path);

    QGraphicsView view(&scene.scene);
    //qDebug() << view.size().height() ;

    init(&view);
    scene.scene.setSceneRect(0,0,view.size().width(),view.size().height());
    view.show();

    return a.exec();
}


