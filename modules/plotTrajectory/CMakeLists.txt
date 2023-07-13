cmake_minimum_required(VERSION 3.0.2)
project(plotTrajectory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TRAJECTORY_SOURCE_FILES # name
        src/DrawTrajectory.cpp
)

add_library(plotTrajectory # library name
        ${TRAJECTORY_SOURCE_FILES}    # add all files in MODULE1_SOURCE_FILES
)

find_package(Pangolin REQUIRED HINTS ${CMAKE_SOURCE_DIR}//thirdParty/pangolin/install/lib/cmake/Pangolin) # .cmake 파일 위치
find_package(Eigen3 REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdParty/Eigen3/install/share/eigen3/cmake) # .cmake 파일 위치

if (Pangolin_FOUND)
    message(STATUS "Pangolin Found! - ${Pangolin_DIR}")
endif()
if (Eigen3_FOUND)
    message(STATUS "Eigen3 Found! - ${Eigen3_DIR}")

    set(Eigen3_LIBS Eigen3::Eigen)
endif()

target_include_directories(plotTrajectory PUBLIC # header file directory
        include # directory
        ${Pangolin_INCLUDE_DIRS}
        ${Eigen3_INCLUDE_DIRS}
)

target_link_libraries(plotTrajectory PUBLIC # library link
        ${Pangolin_LIBRARY}
        ${Eigen3_LIBS}
)