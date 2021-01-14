#include <iostream>
#include "GameEngine/Log.h"
#include "GameEngine/EntryPoint.h"
#define GLFW_INCLUDE_NONE



int main(int argc, char *argv[]) {
    Log::Init();
    //TODO : 进入界面，设置键和开始键，设置键调整config文件，开始键启动游戏引擎
    /*
     * write code here
    */

    //game engine run
    run();


    return 0;
}


