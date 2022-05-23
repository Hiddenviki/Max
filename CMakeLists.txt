cmake_minimum_required(VERSION 3.20)
project(Max4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Max4 main.cpp FIO.h FIO.cpp Address.h Address.cpp Date.h Date.cpp common.cpp common.h letter.cpp letter.h Check.cpp StreamTable.h letter1.cpp letter1.h)
