cmake_minimum_required(VERSION 3.10)

project(dvix_screensaver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
)

add_executable(dvix_screensaver ${SOURCES})

target_include_directories(dvix_screensaver PUBLIC "${PROJECT_SOURCE_DIR}/src")
