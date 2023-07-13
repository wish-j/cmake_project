#include "Eigen/Core"
#include "plotTrajectory/DrawTrajectory.hpp"

// 미리 저장된 궤적을 그리는 프로그램이다.

// path to trajectory file
std::string trajectory_file = "/home/wish/catkin_ws/src/hello_cmake/examples/trajectory.txt";


int main(int argc, char **argv) {
    std::vector<Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>> poses; // 위치 저장 변수
    std::ifstream fin(trajectory_file); // file exist check

    if (!fin) {
        std::cout << "cannot find trajectory file at " << trajectory_file << std::endl;
        return 1;
    }

    while (!fin.eof()) {
        double time, tx, ty, tz, qx, qy, qz, qw;        // tranlation x, y, z & quaternion x, y, z, w
        fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;   // poses extract from file
        Eigen::Isometry3d Twr(Eigen::Quaterniond(qw, qx, qy, qz));
        Twr.pretranslate(Eigen::Vector3d(tx, ty, tz));
        poses.push_back(Twr);     // add data to poses
    }
    std::cout << "read total " << poses.size() << " pose entries" << std::endl;

    // draw trajectory in pangolin
    DrawTrajectory(poses);
    return 0;
}

