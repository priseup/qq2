cmake_minimum_required(VERSION 3.0)

PROJECT(sqlite3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic")

set(src_list src/sqlite3.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
add_library(${PROJECT_NAME} ${src_list})
# target_link_libraries()
