#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "view/LoadingScene.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QFileInfo>

#include "view/WindowController.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString s = ":resources/pic/city.png";

    WindowController window;
    QGraphicsView* view = window.getView();
    LoadingScene scene(view,&s);
    BasicScene * p = (BasicScene*)&scene;
    window.setBasicScene(p);
    window.run();
    view->show();

    return a.exec();
}


