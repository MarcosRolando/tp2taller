//
// Created by marcos on 8/5/20.
//

#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {
    wheat = 0;
    coal = 0;
    wood = 0;
    iron = 0;
}

void Inventory::store(Resource resource) { //switch no me deja usar el unique lock xd
    if (resource == Wheat) {
        std::unique_lock<std::mutex> l(wheatMtx);
        wheat++;
    } else if (resource == Coal) {
        std::unique_lock<std::mutex> l(coalMtx);
        coal++;
    } else if (resource == Wood) {
        std::unique_lock<std::mutex> l(woodMtx);
        wood++;
    } else if (resource == Iron) {
        std::unique_lock<std::mutex> l(ironMtx);
        iron++;
    }
}

void Inventory::print() {
    std::cout << "Wheat: " << wheat << std::endl;
    std::cout << "Wood: " << wood << std::endl;
    std::cout << "Coal: " << coal << std::endl;
    std::cout << "Iron: " << iron << std::endl;
}

