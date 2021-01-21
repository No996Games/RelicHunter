cmake_minimum_required(VERSION 3.17)
project(RelicHunter)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_INCLUDE_CURRENT_DIR ON)


include_directories(src/include src/GameEngine)
add_executable(RelicHunter src/main.cpp
        src/GameEngine/Model/entity/Entity.cpp
        src/GameEngine/Model/entity/Entity.h
        src/GameEngine/Model/scene/Scene.cpp
        src/GameEngine/Model/scene/Scene.h
        src/GameEngine/Model/core/GameEngine.cpp
        src/GameEngine/Model/core/GameEngine.h
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
        src/GameEngine/View/common/Cursor.h
        src/GameEngine/Core.h
        src/GameEngine/EntryPoint.h
        src/GameEngine/View/InputHandlers/InputHandler.h
        src/GameEngine/View/glShader/Shader.h
        src/GameEngine/View/glShader/Shader.cpp
        src/GameEngine/View/Texture.cpp
        src/GameEngine/View/Texture.h
        src/include/stb_image.cpp
        src/include/Tools.h src/include/glm/glm.hpp
        src/include/glm/gtc/matrix_transform.hpp
        src/include/glm/gtc/type_ptr.hpp
        src/GameEngine/Events/KeyCode.h)

# Get architechture info

if(APPLE)
    EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )
    if (${ARCHITECTURE} STREQUAL "arm64")
        target_link_libraries(RelicHunter /opt/homebrew/Cellar/glfw/3.3.2/lib/libglfw.3.dylib)
    else()
        target_link_libraries(RelicHunter ${PROJECT_SOURCE_DIR}/src/include/libglfw.3.dylib)
    endif() #ARCHITECTURE
else()
    # for windows
    target_link_libraries(RelicHunter -lglfw3 -opengl32)
endif () #APPLE

#target_link_libraries(RelicHunter Qt5::Widgets -lmingw32 -lSDL2main -lSDL2)