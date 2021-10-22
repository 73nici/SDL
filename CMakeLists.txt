cmake_minimum_required(VERSION 3.20)
project(SDL_CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(SDL_CPP main.cpp src/Framework.cpp include/Framework.h src/Game.cpp include/Game.h include/Singleton.h src/Player.cpp include/Player.h)

target_include_directories(SDL_CPP PUBLIC include)

target_link_libraries(SDL_CPP ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})