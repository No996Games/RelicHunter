//
// Created by Yuchen Shen on 30/12/20.
//

#ifndef RELICHUNTER_GAMEENGINE_H
#define RELICHUNTER_GAMEENGINE_H
#include "src/GameEngine/Model/scene/Scene.h"

class GameEngine {
public:
    Scene currentScene;
    void tick();
};


#endif //RELICHUNTER_GAMEENGINE_H
