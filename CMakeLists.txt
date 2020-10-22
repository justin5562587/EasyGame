cmake_minimum_required(VERSION 3.16)
project(EasyGame)

set(CMAKE_CXX_STANDARD 11)

set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src/)

# add the  header path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(FILES_HEADER
        ${INCROOT}/Action.hpp
        ${INCROOT}/ActionTarget.hpp
        ${INCROOT}/ActionTarget.tpl
        ${INCROOT}/ActionMap.hpp
        ${INCROOT}/ActionMap.tpl
        ${INCROOT}/Configuration.hpp
        ${INCROOT}/Collision.hpp
        ${INCROOT}/Entity.hpp
        ${INCROOT}/Entity.tpl
        ${INCROOT}/Enemy.hpp
        ${INCROOT}/Game.hpp
        ${INCROOT}/Meteor.hpp
        ${INCROOT}/Player.hpp
        ${INCROOT}/random.hpp
        ${INCROOT}/ResourceManager.hpp
        ${INCROOT}/ResourceManager.tpl
        ${INCROOT}/Saucer.hpp
        ${INCROOT}/Shoot.hpp
        ${INCROOT}/World.hpp
        )

set(FILES_SRC
        ${SRCROOT}/Action.cpp
        ${SRCROOT}/Configuration.cpp
        ${SRCROOT}/Collision.cpp
        ${SRCROOT}/Entity.cpp
        ${SRCROOT}/Enemy.cpp
        ${SRCROOT}/Game.cpp
        ${SRCROOT}/Meteor.cpp
        ${SRCROOT}/Player.cpp
        ${SRCROOT}/Saucer.cpp
        ${SRCROOT}/Shoot.cpp
        ${SRCROOT}/World.cpp
        ${SRCROOT}/main.cpp
        )

set(SFML_DIR "/Users/justin/cpp/SFML_BUILD")
set(BOX2D_DIR "/Users/justin/cpp/box2d/build/src")

find_package(SFML REQUIRED COMPONENTS graphics window system)

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
#find_package(BOX2D REQUIRED)
#if(BOX2D_FOUND)
#    include_directories(${BOX2D_INCLUDE_DIR})
#    target_link_libraries(${EXECUTABLE_NAME} ${BOX2D_LIBRARY})
#endif()

add_executable(EasyGame ${FILES_HEADER} ${FILES_SRC})

#target_link_libraries(EasyGame sfml-graphics sfml-window sfml-system box2d)
target_link_libraries(EasyGame sfml-graphics sfml-window sfml-system sfml-audio)
