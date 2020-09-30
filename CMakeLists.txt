cmake_minimum_required(VERSION 3.16)
project(EasyGame)

set(CMAKE_CXX_STANDARD 11)

#set(SFML_DIR "/Users/justin/cpp/SFML-2.5.1-macos-clang")
set(SFML_DIR "/Users/justin/cpp/SFML_BUILD")

#set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS graphics window system)

add_executable(EasyGame main.cpp)

target_link_libraries (EasyGame sfml-graphics sfml-window sfml-system)
