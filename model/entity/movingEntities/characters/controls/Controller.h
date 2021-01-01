//
// Created by Yuchen Shen on 1/1/21.
//

#ifndef RELICHUNTER_CONTROLLER_H
#define RELICHUNTER_CONTROLLER_H
#include "../Character.h"
class Controller{
public:
    Character character;
    Controller(Character character){
        this->character = character;
    }
    //control the action of Character
    virtual void control() = 0;
};
#endif //RELICHUNTER_CONTROLLER_H
