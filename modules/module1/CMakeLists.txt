cmake_minimum_required(VERSION 3.0.2)
# cmake_policy(SET CMP0111 OLD)
project(module1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULE1_SOURCE_FILES # name
        src/ClassMat.cpp
        )

add_library(module1 # library name
        ${MODULE1_SOURCE_FILES}    # add all files in MODULE1_SOURCE_FILES
        )

# OpenCV package
find_package(OpenCV REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdParty/OpenCV/install/lib/cmake/opencv4)

# if find, print directory
if (OpenCV_FOUND)
    message(STATUS "OpenCV Found! - ${OpenCV_DIR}")
endif()

# header file directory
target_include_directories(module1 PUBLIC
        include # directory
        ${OpenCV_INCLUDE_DIRS}
        )

# library link - library link in module1
target_link_libraries(module1 PUBLIC
        ${OpenCV_LIBS}
        )
