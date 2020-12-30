#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "GUI/LoadingScene.h"
#include <QString>

#define SCREENWIDTH 1000
#define SCREENHEIGHT 800


void init(QGraphicsView * w){
    w->resize(SCREENWIDTH,SCREENHEIGHT);
    w->setWindowFlags(Qt::FramelessWindowHint);
    w->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    w->show();

}
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString path = "resources/city.png";
    LoadingScene scene(&path);


    QGraphicsView view(&scene.scene);
    init(&view);
    view.show();
    return a.exec();
}


