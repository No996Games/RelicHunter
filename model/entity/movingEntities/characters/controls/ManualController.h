//
// Created by Yuchen Shen on 1/1/21.
//

#ifndef RELICHUNTER_MANUALCONTROLLER_H
#define RELICHUNTER_MANUALCONTROLLER_H
#include "Controller.h"
class ManualController: Controller{

    int moveRight = 0;
    int moveLeft = 0;
    int moveUp = 0;
    int moveDown = 0;

    void stopMove(){
        moveRight = 0;
        moveLeft = 0;
        moveUp = 0;
        moveDown = 0;
    }
    void control() {

        // 这里我不确定这么写对不对，用起来滑溜不滑溜
        if (moveRight && moveUp) {
            character.moveUpRight();
        } else if (moveRight && moveDown) {
            character.moveDownRight();
        } else if (moveLeft && moveUp) {
            character.moveUpLeft();
        } else if (moveLeft && moveDown) {
            character.moveDownLeft();
        } else if (moveLeft) {
            character.moveLeft();
        } else if (moveRight){
            character.moveRight();
        }
    }
};

#endif //RELICHUNTER_MANUALCONTROLLER_H
