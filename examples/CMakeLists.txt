# include_directories("/usr/include/eigen3")
add_executable(coordinateTransform coordinateTransform.cpp)
add_executable(plotTrajectory plotTrajectory.cpp)

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
        ${Pangolin_INCLUDE_DIRS}
)
target_link_libraries(plotTrajectory PUBLIC # library link
        ${Pangolin_LIBRARY}
)
target_include_directories(coordinateTransform PUBLIC # header file directory
        ${Eigen3_INCLUDE_DIRS}
)
target_link_libraries(coordinateTransform PUBLIC # library link
        ${Eigen3_LIBS}
)