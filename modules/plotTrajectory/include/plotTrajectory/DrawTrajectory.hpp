#ifndef HELLO_CMAKE_DRAWTRAJECTORY_HPP
#define HELLO_CMAKE_DRAWTRAJECTORY_HPP

#include <unistd.h>
#include "pangolin/pangolin.h"
#include "Eigen/Core"

void DrawTrajectory(const std::vector<Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>>& poses); // function 선언

#endif //HELLO_CMAKE_DRAWTRAJECTORY_HPP
