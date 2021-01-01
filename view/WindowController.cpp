//
// Created by Yuchen Shen on 2/1/21.
//

#include "WindowController.h"

void WindowController::run() {
    QTimeLine *timeLine = new QTimeLine(1000);
    timeLine->setFrameRange(0, 100);
    timeLine->setLoopCount(0);
    connect(timeLine,&QTimeLine::frameChanged, this, &WindowController::tick);
    timeLine->start();
}

void WindowController::tick(int frameCount) {
    if (currentScene == nullptr) {
        return;
    }
    currentScene->tick(frameCount);
}
