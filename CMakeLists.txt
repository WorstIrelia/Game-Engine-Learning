cmake_minimum_required(VERSION 3.1)
set (CMAKE_C_STANDAR{D 11)
set (CMAKE_CXX_STANDARD 11)
project (GameEngine)
include_directories("${PROJECT_SOURCE_DIR}/Framework/Common")
include_directories("${PROJECT_SOURCE_DIR}/Framework/Interface")
add_subdirectory(Framework)
add_subdirectory(Empty)