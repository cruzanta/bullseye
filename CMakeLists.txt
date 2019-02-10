cmake_minimum_required(VERSION 3.7.2)
project(BullseyeGame)

# Headers
include_directories(include)

# OpenGL & GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

file(GLOB_RECURSE bullseye_SOURCES "src/main.cpp")

add_executable(Bullseye ${bullseye_SOURCES})

target_link_libraries(Bullseye ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
