cmake_minimum_required(VERSION 3.0.0)
project(CVTesting VERSION 0.1.0)

include(CTest)
enable_testing()
find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)
include_directories(headers/CameraDetect.hpp)
add_executable(CVTesting test/test4.cpp)
target_compile_features(CVTesting PUBLIC cxx_std_17)
set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



target_link_libraries(CVTesting ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})
