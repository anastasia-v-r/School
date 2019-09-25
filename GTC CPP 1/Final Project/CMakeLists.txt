    
cmake_minimum_required(VERSION 3.1...3.14.3)

project (program_final_project)
set (CMAKE_CXX_STANDARD 17)
set (WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/assets)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

file(COPY ${PROJECT_SOURCE_DIR}/accs DESTINATION ${CMAKE_BINARY_DIR}/bin)

FILE(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(program_final_project ${sources})