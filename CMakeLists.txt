cmake_minimum_required(VERSION 3.3)
project(MotionSim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES src/main.cpp src/display.cpp src/display.h src/body.cpp src/body.h src/simulation.cpp src/simulation.h src/shader.cpp src/shader.h src/controller.cpp src/controller.h)
add_executable(MotionSim ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

INCLUDE(FindGLEW)

INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GLEW_LIBRARIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} GL)
