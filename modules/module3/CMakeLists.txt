cmake_minimum_required(VERSION 3.0.2)
project(module3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULE3_SOURCE_FILES # name
        src/ClassPangolinMat.cpp
)

add_library(module3 # library name
        ${MODULE3_SOURCE_FILES}    # add all files in MODULE1_SOURCE_FILES
)

find_package(Pangolin REQUIRED HINTS ${CMAKE_SOURCE_DIR}//thirdParty/pangolin/install/lib/cmake/Pangolin) # .cmake 파일 위치

if (Pangolin_FOUND)
    message(STATUS "Pangolin Found! - ${Pangolin_DIR}")
endif()

target_include_directories(module3 PUBLIC # header file directory
        include # directory
        ${Pangolin_INCLUDE_DIRS}
)

target_link_libraries(module3 PUBLIC # library link
        ${Pangolin_LIBRARY}
)