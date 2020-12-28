cmake_minimum_required(VERSION 3.17)
project(RelicHunter)



set(CMAKE_CXX_STANDARD 14)

if( APPLE )
    set (CMAKE_PREFIX_PATH "~/Qt/5.15.2/clang_64/lib/cmake")
elseif( UNIX AND NOT APPLE )
    # SET unix 默认路径
elseif(WIN32)
    set (CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
elseif(WIN64)
    set (CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
endif( APPLE )

find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(RelicHunter main.cpp animationWindow/Animation.cpp animationWindow/Animation.h)
target_link_libraries(RelicHunter Qt5::Widgets)
