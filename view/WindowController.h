//
// Created by Yuchen Shen on 1/1/21.
//

#ifndef RELICHUNTER_WINDOWCONTROLLER_H
#define RELICHUNTER_WINDOWCONTROLLER_H
#include <QGraphicsView>
#include <QTimeLine>
#include "BasicScene.h"
class WindowController: QGraphicsView {
    Q_OBJECT
private:
    BasicScene *currentScene;

    void init(QGraphicsView *w) {
        //w->setWindowFlags(Qt::FramelessWindowHint);
        w->setWindowFlags(Qt::Window);
        w->setWindowTitle("RelicHunter");
        w->showFullScreen();
        w->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        w->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        w->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        w->show();
    }

public slots:
    void tick(int frameCount);

public:
    WindowController() {
        currentScene = nullptr;
        init(this);
    }
    void setBasicScene(BasicScene* scene){
        currentScene = scene;
        this->setScene(scene->getScene());
    }
    QGraphicsView *getView() {
        return this;
    }

    void run();
};


#endif //RELICHUNTER_WINDOWCONTROLLER_H
