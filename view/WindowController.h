//
// Created by Yuchen Shen on 1/1/21.
//

#ifndef RELICHUNTER_WINDOWCONTROLLER_H
#define RELICHUNTER_WINDOWCONTROLLER_H
#include <QGraphicsView>
#include <QTimeLine>
#include <QProgressBar>
class WindowController : QObject{
private:
    QProgressBar b;
    QGraphicsView view;
    BasicScene* currentScene;
    void init(QGraphicsView * w){
        //w->setWindowFlags(Qt::FramelessWindowHint);
        w->setWindowFlags(Qt::Window);
        w->setWindowTitle("RelicHunter");
        w->showFullScreen();
        w->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        w->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        w->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        w->show();
    }
public:
    WindowController(){
        init(&view);
    }
    QGraphicsView* getView(){
        return &view;
    }
    void setScene(BasicScene* scene){
        currentScene = scene;
        view.setScene(scene->getScene());
    }

    void run() {
        QTimeLine *timeLine = new QTimeLine(1000);
        timeLine->setFrameRange(0, 100);
        timeLine->setLoopCount(0);
        timeLine->connect(timeLine, SIGNAL(frameChanged(int)), (this), SLOT(tick(int)));
    }
    void tick(int frameCount){
        if(currentScene == nullptr){
            return;
        }
        currentScene->tick(frameCount);
    }
};


#endif //RELICHUNTER_WINDOWCONTROLLER_H
