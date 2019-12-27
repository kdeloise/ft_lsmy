cmake_minimum_required(VERSION 3.14)
project(ft_lsmy C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_lsmy
        ft_ls.c
        ft_ls.h)
