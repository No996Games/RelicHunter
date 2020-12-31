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
    WIDTH = w->size().width();
    HEIGHT = w->size().height();
    w->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    w->show();

}
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString path = ":/resources/pic/city.png";

    LoadingScene scene(&path);
    QGraphicsView view(&scene.scene);

    init(&view);
    return a.exec();
}


