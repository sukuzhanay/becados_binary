cmake_minimum_required(VERSION 3.15)
project(becados_io_bin)

set(CMAKE_CXX_STANDARD 14)

add_executable(becados_io_bin
        main.cpp
        solicitantes.txt)
