//
// Created by Yuchen Shen on 30/12/20.
//

#ifndef RELICHUNTER_SCENE_H
#define RELICHUNTER_SCENE_H
#include "src/GameEngine/Model/entity/Entity.h"
#include "src/GameEngine/Model/entity/movingEntities/MovingEntity.h"
#include <vector>
class Scene {
public:
    vector<Entity> entities;
    vector<MovingEntity> movingEntities;
    void tick(){

        // 会动的entity动
        for (int i = 0; i<movingEntities.size(); ++i)
        {
            movingEntities[i].tick();
        }

    }
};


#endif //RELICHUNTER_SCENE_H
