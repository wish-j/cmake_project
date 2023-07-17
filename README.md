# cmake_project

### 프로그래머스 자율주행 데브코스
12주차 SLAM - Coordinate Transformation 과제

### Done
- Eigen, Pangolin 빌드
- 아래 경로의 코드를 main문으로 하는 C++프로젝트를 생성.
- https://github.com/gaoxiang12/slambook2/blob/master/ch3/examples/plotTrajectory.cpp
- main문 코드에 주석 추가
- 코드 실행결과를 screenshot 폴더에 첨부
- Using namespace 제거, main.cpp 헤더파일 분리

### Code feedback
- .gitignore에 불필요한 폴더제거 항목 추가
- main.cpp 파일 위치 변경 (최상위 경로 -> examples)
- odules 폴더에는 library를 이루는 파일로만 구성
- modules 폴더 내부 CMakeLists.txt에서 cmake_minimum 및 project 선언부 제거.
- -> subproject로 다뤄짐을 방지하여 최상위 경로에서 설정해둔 cmake 버전 및 프로젝트 명이 바뀌는 현상 방지.
- std::vector를 함수 인자로 사용부에서 const std::vector<...>& vec와 같은 const-reference 형태로 넘겨줌으로써 복사 작업 방지


<img width="879" alt="image" src="https://github.com/wish-j/cmake_project/assets/125460753/535eeb32-bc2d-4a21-8924-d1105ca68b68">
