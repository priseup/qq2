cmake_minimum_required(VERSION 3.0)

PROJECT(qq2)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(src_list ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${src_list})
target_link_libraries(${PROJECT_NAME} m dl)
