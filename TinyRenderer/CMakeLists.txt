cmake_minimum_required(VERSION 3.0.0)
project(TinyRenderer VERSION 0.1.0)


set(RENDERER_SRCS
lib.h
lib.cpp
face.h
color.h
geometry.h
geometry.cpp
buffer.h
buffer.cpp
model.h
model.cpp
render.h
render.cpp
)

add_compile_definitions(BUILD_DLL)

add_library(TinyRenderer SHARED ${RENDERER_SRCS})

set_target_properties(${PROJECT_NAME} PROPERTIES C_STANDARD 99 CXX_STANDARD 11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})