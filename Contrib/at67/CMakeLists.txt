cmake_minimum_required(VERSION 3.7)

project(gtemuSDL)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
if(APPLE)
    set(CMAKE_CXX_FLAGS "-std=c++14")
endif()

add_subdirectory(midi)
add_subdirectory(tools/gtasm)
add_subdirectory(tools/gt1torom)
add_subdirectory(tools/gtmakerom)
add_subdirectory(tools/gtsplitrom)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

file(GLOB headers *.h)
file(GLOB sources *.cpp)
set(headers ${headers})
set(sources ${sources})

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_executable(gtemuSDL WIN32 dirent/dirent.h inih/INIReader.h rs232/rs232.h ${headers} rs232/rs232-win.c ${sources})
else()
    add_executable(gtemuSDL inih/INIReader.h rs232/rs232.h ${headers} rs232/rs232-linux.c ${sources})
endif()

target_link_libraries(gtemuSDL ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY})