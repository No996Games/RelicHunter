#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "view/LoadingScene.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include "GameEngine/Log.h"

#include "view/WindowController.h"
int main(int argc, char *argv[]) {

    Log::Init();
    GE_CORE_WARN("Initialized Log!");
    GE_CORE_INFO("Hello!");

    QApplication a(argc, argv);
    QString s = ":resources/pic/city.png";

    WindowController window;
    QGraphicsView* view = window.getView();
    LoadingScene scene(view,&s);
    BasicScene * p = (BasicScene*)&scene;
    window.setBasicScene(p);
    view->show();
    
    return a.exec();
}


