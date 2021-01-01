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

add_executable(RelicHunter main.cpp
        model/entity/Entity.cpp
        model/entity/Entity.h
        model/scene/Scene.cpp
        model/scene/Scene.h
        model/GameEngine.cpp
        model/GameEngine.h
        view/LoadingScene.h
        resources.qrc
        model/entity/movingEntities/MovingEntity.h
        model/entity/movingEntities/characters/Character.h
        model/entity/movingEntities/characters/controls/Controller.h
        model/entity/movingEntities/characters/controls/ManualController.h
        view/WindowController.h
        view/BasicScene.h)

set(QRC_FILE resource.qrc)
qt5_add_resources(QRC ${QRC})

target_link_libraries(RelicHunter Qt5::Widgets)

#target_link_libraries(RelicHunter Qt5::Widgets -lmingw32 -lSDL2main -lSDL2)