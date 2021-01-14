cmake_minimum_required(VERSION 3.17)
project(RelicHunter)

set(CMAKE_CXX_STANDARD 14)
if(APPLE)
    set (CMAKE_PREFIX_PATH "~/Qt/5.15.2/clang_64/lib/cmake")
elseif(UNIX AND NOT APPLE)
    # SET unix 默认路径
elseif(WIN32 OR WIN64)
    set (CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
endif(APPLE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
#我暂时没有sdl，用的时候把警号删了
#find_package(SDL2 REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(src/include src/GameEngine)

add_executable(RelicHunter src/main.cpp
        src/GameEngine/Model/entity/Entity.cpp
        src/GameEngine/Model/entity/Entity.h
        src/GameEngine/Model/scene/Scene.cpp
        src/GameEngine/Model/scene/Scene.h
        src/GameEngine/Model/core/GameEngine.cpp
        src/GameEngine/Model/core/GameEngine.h
        resources.qrc
        src/GameEngine/Model/entity/movingEntities/MovingEntity.h
        src/GameEngine/Model/entity/movingEntities/characters/Character.h
        src/GameEngine/Model/entity/movingEntities/characters/controls/Controller.h
        src/GameEngine/Model/entity/movingEntities/characters/controls/ManualController.h
        src/GameEngine/Log.cpp src/GameEngine/Log.h
        src/glad.c
        src/GameEngine/Events/ApplicationEvent.h
        src/GameEngine/Events/Event.h
        src/GameEngine/Events/KeyEvent.h
        src/GameEngine/Events/MouseEvent.h
        src/GameEngine/Core.h src/GameEngine/EntryPoint.h src/GameEngine/View/InputHandlers/KeyBoardHandler.h src/GameEngine/View/glShader/Shader.h src/GameEngine/View/glShader/Shader.cpp src/GameEngine/View/Texture.cpp src/GameEngine/View/Texture.h src/include/stb_image.cpp)
add_library(stb_image.cpp)
set(QRC_FILE resource.qrc)
qt5_add_resources(QRC ${QRC})

# Get architechture info
#EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )
#if (${ARCHITECTURE} STREQUAL "arm64" AND APPLE)
#    target_link_libraries(RelicHunter /opt/homebrew/Cellar/glfw/3.3.2/lib/libglfw.3.dylib)
#else
if(APPLE)
    # for mac go here
    target_link_libraries(RelicHunter Qt5::Widgets ${PROJECT_SOURCE_DIR}/src/include/libglfw.3.dylib)
else()
    # for windows
    target_link_libraries(RelicHunter Qt5::Widgets -lglfw3 -opengl32)
endif () #ARCHITECTURE

#target_link_libraries(RelicHunter Qt5::Widgets -lmingw32 -lSDL2main -lSDL2)