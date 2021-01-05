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

include_directories(src/include)

add_executable(RelicHunter src/main.cpp
        src/Model/entity/Entity.cpp
        src/Model/entity/Entity.h
        src/Model/scene/Scene.cpp
        src/Model/scene/Scene.h
        src/Model/core/GameEngine.cpp
        src/Model/core/GameEngine.h
        src/view/LoadingScene.h
        resources.qrc
        src/Model/entity/movingEntities/MovingEntity.h
        src/Model/entity/movingEntities/characters/Character.h
        src/Model/entity/movingEntities/characters/controls/Controller.h
        src/Model/entity/movingEntities/characters/controls/ManualController.h
        src/view/BasicScene.h
        src/view/WindowController.h
        src/view/BasicScene.h
        src/view/WindowController.cpp
        src/view/animation/Animation.cpp
        src/view/animation/Animation.h
        src/Game.h
        src/GameEngine/Log.cpp src/GameEngine/Log.h)

set(QRC_FILE resource.qrc)
qt5_add_resources(QRC ${QRC})

target_link_libraries(RelicHunter Qt5::Widgets)

#target_link_libraries(RelicHunter Qt5::Widgets -lmingw32 -lSDL2main -lSDL2)