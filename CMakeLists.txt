cmake_minimum_required(VERSION 3.16)
project(tp2taller)

add_executable(tp2taller main.cpp FileReader.cpp FileReader.h
        NonExistentFileException.cpp NonExistentFileException.h)

target_compile_options (tp2taller PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O0 -ggdb -DDEBUG -fno-inline)

target_link_options(tp2taller PRIVATE -lm -pthread)