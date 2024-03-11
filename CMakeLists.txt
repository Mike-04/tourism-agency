cmake_minimum_required(VERSION 3.27)
project(Lab2_4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab2_4
        domain.c
        domain.h
        main.c
        repo.c
        repo.h
        service.c
        service.h
        ui.c
        ui.h)
