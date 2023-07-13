cmake_minimum_required(VERSION 3.0.2)
project(hello_cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(modules)

add_executable(main main.cpp)

# exec_module1에 library를 링크
target_link_libraries(main PUBLIC
        plotTrajectory
)