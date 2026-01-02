cmake_minimum_required(VERSION 3.10)
project(sodaview)

add_library(sodaview SHARED 
    sodaview/src/sodaview/application.cpp
    sodaview/src/sodaview/application.h
    sodaview/src/sodaview/entrypoint.h
    sodaview/src/sodaview.h

)


add_executable(sandbox sandbox/src/sandbox.cpp)

target_link_libraries(sodaview PRIVATE SDL2)
target_link_libraries(sandbox PRIVATE sodaview SDL2)

target_include_directories(sodaview PUBLIC src /usr/include/SDL2)
target_include_directories(sandbox PRIVATE /usr/include/SDL2)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)