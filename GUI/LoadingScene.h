//
// Created by Yuchen Shen on 30/12/20.
//

#ifndef RELICHUNTER_LOADINGSCENE_H
#define RELICHUNTER_LOADINGSCENE_H


#include <QGraphicsScene>
#include <QPixmap>
#include <QString>
class LoadingScene{
public:
    QGraphicsScene scene;
    LoadingScene(QString *filenames){
        QPixmap image = QPixmap(*filenames);
        scene.addPixmap(image);
        //scene.addText("sss");
    }
};
#endif //RELICHUNTER_LOADINGSCENE_H
