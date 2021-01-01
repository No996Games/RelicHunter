//
// Created by Yuchen Shen on 1/1/21.
//

#ifndef RELICHUNTER_WINDOWCONTROLLER_H
#define RELICHUNTER_WINDOWCONTROLLER_H
#include <QGraphicsView>
class WindowController {
private:
    QGraphicsView view;
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
        view.setScene(scene->getScene());
    }
};


#endif //RELICHUNTER_WINDOWCONTROLLER_H
