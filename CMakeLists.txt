# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.27.7)

# Set the project name
project (vpn)

# Add an executable
add_executable(vpn main.cpp)