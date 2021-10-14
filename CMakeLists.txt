cmake_minimum_required(VERSION 3.20)
project(SDL_CPP)

set(CMAKE_CXX_STANDARD 17)
include_directories(${SDL2_INCLUDE_DIRS})
find_package(SDL2 REQUIRED)

add_executable(SDL_CPP main.cpp src/Framework.cpp include/Framework.h src/Game.cpp include/Game.h include/Singleton.h src/Player.cpp include/Player.h)

target_include_directories(SDL_CPP PUBLIC include)

target_link_libraries(SDL_CPP ${SDL2_LIBRARIES})