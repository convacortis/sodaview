cmake_minimum_required(VERSION 3.14)
project(Sodaview
  VERSION 1.0.0
  LANGUAGES CXX C
)
cmake_policy(SET CMP0072 NEW)

include(FetchContent)



# fetch GLFW from github mirror
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)


set(GLFW_BUILD_X11 ON CACHE BOOL "" FORCE)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)



FetchContent_MakeAvailable(glfw)




# make sure vulkan is found and added
find_package(Vulkan REQUIRED)

if (Vulkan_FOUND)
  include_directories(${Vulkan_INCLUDE_DIRS})
  link_directories(${Vulkan_LIBRARY_DIRS})
endif ()



file(GLOB_RECURSE SODAVIEW_SOURCES 
  "sodaview/src/*.cpp"
  "sodaview/src/*.h"
)


add_library(sodaview SHARED 

  ${SODAVIEW_SOURCES}

)




# create main executable for program
add_executable(sandbox
  sandbox/src/sandbox.cpp
)





target_link_libraries(sodaview 
  glfw
  ${Vulkan_LIBRARY}
)

target_link_libraries(sandbox 
  sodaview 
  glfw
  ${Vulkan_LIBRARY}
)





