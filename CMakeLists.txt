cmake_minimum_required(VERSION 3.24)
project(pea_projekt_brute_force_v2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(pea_projekt_brute_force_v2 main.cpp drugi.cpp drugi.h)
