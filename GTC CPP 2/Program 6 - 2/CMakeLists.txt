cmake_minimum_required(VERSION 3.1...3.14.3)

project (2program_6_2)
set (CMAKE_CXX_STANDARD 17)

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp
	${PROJECT_SOURCE_DIR}/*.hpp
)

add_executable(2program_6_2 ${sources})