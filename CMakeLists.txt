cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        include/riscv_instructions.h
        src/riscv_instructions.cpp
        z_reste/rest.cpp
        src/riscv_simulator.cpp
        include/riscv_simulator.h
)
