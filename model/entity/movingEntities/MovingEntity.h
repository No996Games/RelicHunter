s//
// Created by Yuchen Shen on 31/12/20.
//

#ifndef RELICHUNTER_MOVINGENTITY_H
#define RELICHUNTER_MOVINGENTITY_H
#include "../Entity.h"
#define BASICSPEED 10
class MovingEntity:Entity{
public:
    using Entity::Entity;
    void tick() {
        x = x + velox;
        y = y + veloy;
    }
protected:
    double velox = 0;
    double veloy = 0;
};
#endif //RELICHUNTER_MOVINGENTITY_H
