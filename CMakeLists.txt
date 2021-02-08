cmake_minimum_required (VERSION 3.0)

project (raytracing
    LANGUAGES CXX
)

set (CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Debug)
endif (NOT CMAKE_BUILD_TYPE)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fsanitize=address")

set (SOURCE_RAYTRACING
    src/vec3.h
    src/color.h
    src/ray.h
)

add_executable(raytracing   src/main.cpp    ${SOURCE_RAYTRACING})
