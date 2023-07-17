add_executable(main main.cpp)

# exec_module1에 library를 링크
target_link_libraries(main PUBLIC
        plotTrajectory
)