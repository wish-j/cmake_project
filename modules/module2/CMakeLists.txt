cmake_minimum_required(VERSION 3.0.2)
project(module2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULE2_SOURCE_FILES # name
        src/ClassEigenMat.cpp
        )

add_library(module2 # library name
        ${MODULE2_SOURCE_FILES}    # add all files in MODULE1_SOURCE_FILES
        )

find_package(Eigen3 REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdParty/Eigen3/install/share/eigen3/cmake) # .cmake 파일 위치

if (Eigen3_FOUND)
    message(STATUS "Eigen3 Found! - ${Eigen3_DIR}")

    set(Eigen3_LIBS Eigen3::Eigen)
endif()

target_include_directories(module2 PUBLIC # header file directory
        include # directory
        ${Eigen3_INCLUDE_DIRS}
        )

target_link_libraries(module2 PUBLIC # library link
        ${Eigen3_LIBS}
        )