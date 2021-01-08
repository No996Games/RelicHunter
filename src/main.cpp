#include <iostream>
#include "GameEngine/Log.h"
#include "GameEngine/EntryPoint.h"
#define GLFW_INCLUDE_NONE



int main(int argc, char *argv[]) {

    run();
    Log::Init();
    GE_CORE_WARN("Initialized Log!");
    GE_INFO("Hello!");
    GE_CORE_ERROR("Test error");
    GE_CORE_FATAL("Test FATAL");
    GE_CORE_TRACE("Something");

    return 0;
}


