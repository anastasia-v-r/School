    
cmake_minimum_required(VERSION 3.1...3.14.3)

project (program_final_project)
set (CMAKE_CXX_STANDARD 17)

FILE(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(program_final_project ${sources})