cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        Mods.h
        Mods_Body.cpp
        Roles.h
        Roles_Body.cpp
)
