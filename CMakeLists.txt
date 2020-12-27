cmake_minimum_required(VERSION 3.17)
project(RelicHunter)



set(CMAKE_CXX_STANDARD 14)

if( APPLE )
    set (CMAKE_PREFIX_PATH "/Users/yuchen/Qt/5.15.2/clang_64/lib/cmake")
elseif( UNIX AND NOT APPLE )

    # SET unix 默认路径
elseif( WIN64 and WIN32 )
    # SET window 默认路径
endif( APPLE )


find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(RelicHunter main.cpp)
target_link_libraries(RelicHunter Qt5::Widgets)