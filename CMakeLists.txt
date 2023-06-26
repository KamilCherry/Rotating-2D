cmake_minimum_required(VERSION 3.6)
cmake_policy (SET CMP0079 NEW)

set(EXE_NAME "example" CACHE STRING "Name of executable file.")

project($(EXE_NAME) LANGUAGES CXX)

set(src_dir "${CMAKE_SOURCE_DIR}/src/")
set(include_dir "${CMAKE_SOURCE_DIR}/include")
string(LENGTH ${EXE_NAME} EXE_NAME_LENGTH)


file(REMOVE ${CMAKE_BINARY_DIR}/res/)
# file(COPY res/ DESTINATION ${CMAKE_BINARY_DIR}/res/)

file(GLOB src_files "${src_dir}/*.cpp" "${src_dir}/*.c")

add_executable("${EXE_NAME}" "${src_files}")

target_include_directories("${EXE_NAME}" PUBLIC "${include_dir}")
# target_compile_definitions("${EXE_NAME}" PUBLIC EXE_NAME_LENGTH=${EXE_NAME_LENGTH})

add_subdirectory("${CMAKE_SOURCE_DIR}/lib")
