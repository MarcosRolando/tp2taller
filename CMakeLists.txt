cmake_minimum_required(VERSION 3.16)
project(tp2taller)

add_executable(tp2taller main.cpp WorkerReader.cpp WorkerReader.h
        FileException.cpp FileException.h King.cpp King.h ResourceReader.cpp
        ResourceReader.h Resource.h BlockingQueue.cpp BlockingQueue.h
        Gatherer.cpp Gatherer.h Inventory.cpp Inventory.h Resource.h Cook.cpp Cook.h)

target_compile_options (tp2taller PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O0 -ggdb -DDEBUG -fno-inline)

target_link_options(tp2taller PRIVATE -lm -pthread)