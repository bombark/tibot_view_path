cmake_minimum_required (VERSION 2.6)
project (view)
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

find_package( OpenCV REQUIRED )

add_executable (view_path src/main.cpp)
target_link_libraries (view_path tisys tiobj ${OpenCV_LIBS})

install(TARGETS view_path DESTINATION bin)
