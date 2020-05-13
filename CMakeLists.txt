cmake_minimum_required(VERSION 3.16)
project(tp2taller)

add_subdirectory(tests)

add_executable(tp main.cpp WorkerReader.cpp WorkerReader.h
        FileException.cpp FileException.h King.cpp King.h ResourceReader.cpp
        ResourceReader.h Resource.h BlockingQueue.cpp BlockingQueue.h
        Gatherer.cpp Gatherer.h Inventory.cpp Inventory.h Resource.h Cook.cpp
        Cook.h Carpenter.cpp Carpenter.h Armourer.cpp Armourer.h BenefitPoints.cpp
        BenefitPoints.h Producer.cpp Producer.h Thread.cpp Thread.h TP.cpp TP.h)

target_compile_options (tp PRIVATE -std=c++11 -Wall -Werror -pedantic -pedantic-errors
        -O3 -ggdb -DDEBUG -fno-inline)

target_link_options(tp PRIVATE -lm -pthread)