//
// Created by Yuchen Shen on 31/12/20.
//

#ifndef RELICHUNTER_CHARACTER_H
#define RELICHUNTER_CHARACTER_H
#include "../MovingEntity.h"
#include <math.h>
class Character : MovingEntity{
public:
    double speed;
    void moveUp(){
        veloy =  - sqrt(2) * BASICSPEED * speed;
    }
    void moveDown(){
        veloy = sqrt(2) * BASICSPEED * speed;
    }
    void moveRight(){
        velox = sqrt(2) * BASICSPEED * speed;
    }
    void moveLeft(){
        velox = - sqrt(2) * BASICSPEED * speed;
    }
    void moveUpRight(){
        velox = BASICSPEED * speed;
        veloy = - BASICSPEED * speed;
    }
    void moveUpLeft(){
        velox = - BASICSPEED * speed;
        veloy = - BASICSPEED * speed;
    }
    void moveDownRight(){
        velox = BASICSPEED * speed;
        veloy = BASICSPEED * speed;
    }
    void moveDownLeft(){
        velox = - BASICSPEED * speed;
        veloy =  BASICSPEED * speed;
    }
};


#endif //RELICHUNTER_CHARACTER_H
