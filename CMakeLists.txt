cmake_minimum_required(VERSION 3.10)
project(sodaview)

add_library(sodaview SHARED 
    sodaview/src/application.cpp
    sodaview/src/application.h
)


add_executable(main main.cpp)

target_link_libraries(sodaview PRIVATE SDL2)
target_link_libraries(main PRIVATE sodaview SDL2)

target_include_directories(sodaview PUBLIC src /usr/include/SDL2)
target_include_directories(main PRIVATE /usr/include/SDL2)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)