cmake_minimum_required(VERSION 3.6)
project(Prog2_CWK3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Movie.cpp Movie.h MovieDatabase.cpp MovieDatabase.h TimeStamp.cpp TimeStamp.h Rating.cpp Rating.h)
add_executable(Prog2_CWK3 ${SOURCE_FILES})