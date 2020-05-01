cmake_minimum_required(VERSION 3.0)
project(BahKr_Utils)
set(CMAKE_CXX_STANDARD 14)

SET(SRC_FILES src/maths/vector/vec3.cpp src/maths/vector/vec3.h src/maths/matrix/mat4.cpp src/maths/matrix/mat4.h src/maths/vector/vec4.cpp src/maths/vector/vec4.h)

add_executable(BahKr_Utils src/main.cpp ${SRC_FILES})