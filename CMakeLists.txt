cmake_minimum_required(VERSION 3.10)
project(sodaview 
    VERSION 1.0.0
    LANGUAGES CXX C
)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_library(sodaview SHARED 
    sodaview/src/sodaview/application.cpp
    sodaview/src/sodaview/application.h
    sodaview/src/sodaview/entrypoint.h
    sodaview/src/sodaview.h
)


add_executable(sandbox 
    sandbox/src/sandbox.cpp
)


add_library(glad
  STATIC
    vendor/glad/src/glad.c
)
target_include_directories(glad
  PRIVATE
    vendor/glad/include
)



target_link_libraries(sodaview PUBLIC 
    SDL2
    glad
    OpenGL::GL
)

target_link_libraries(sandbox PUBLIC 
    sodaview 
    SDL2
    glad
    OpenGL::GL
)







