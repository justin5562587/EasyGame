cmake_minimum_required(VERSION 3.16)
project(EasyGame)

set(CMAKE_CXX_STANDARD 11)

set(INCLUDE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(FILES_SRC
        ${SRC_ROOT}/Game.cpp
        ${SRC_ROOT}/Player.cpp
#        ${SRC_ROOT}/Action.cpp
#        ${SRC_ROOT}/ActionTarget.cpp
        ${SRC_ROOT}/main.cpp
        )

set(SFML_DIR "/Users/justin/cpp/SFML_BUILD")

find_package(SFML REQUIRED COMPONENTS graphics window system)

add_executable(EasyGame ${FILES_SRC})

target_link_libraries(EasyGame sfml-graphics sfml-window sfml-system)
