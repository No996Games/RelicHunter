//
// Created by Yuchen Shen on 31/12/20.
//

#ifndef RELICHUNTER_MOVINGENTITY_H
#define RELICHUNTER_MOVINGENTITY_H
#include "src/GameEngine/Model/entity/Entity.h"
#define BASIC_SPEED 10
class MovingEntity:Entity{
public:
    using Entity::Entity;
    void tick() {
        x = x + velocityX;
        y = y + velocityY;
    }
protected:
    double velocityX = 0;
    double velocityY = 0;
};
#endif //RELICHUNTER_MOVINGENTITY_H
