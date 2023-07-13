cmake_minimum_required(VERSION 3.0.2)
project(hello_cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(main plotTrajectory.cpp)

find_package(Pangolin REQUIRED HINTS ${CMAKE_SOURCE_DIR}//thirdParty/pangolin/install/lib/cmake/Pangolin) # .cmake 파일 위치

if (Pangolin_FOUND)
    message(STATUS "Pangolin Found! - ${Pangolin_DIR}")
endif()

target_include_directories(main PUBLIC # header file directory
        ${Pangolin_INCLUDE_DIRS}
)
target_link_libraries(main PUBLIC # library link
        ${Pangolin_LIBRARY}
)




add_executable(coordinateTransform coordinateTransform.cpp)

find_package(Eigen3 REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdParty/Eigen3/install/share/eigen3/cmake) # .cmake 파일 위치

if (Eigen3_FOUND)
    message(STATUS "Eigen3 Found! - ${Eigen3_DIR}")

    set(Eigen3_LIBS Eigen3::Eigen)
endif()

target_include_directories(coordinateTransform PUBLIC # header file directory
        ${Eigen3_INCLUDE_DIRS}
)

target_link_libraries(coordinateTransform PUBLIC # library link
        ${Eigen3_LIBS}
)
