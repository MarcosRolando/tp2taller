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
    finishedAdding = false;
}

void Inventory::_notifyProducers() {
    if (wheat >= 2 && coal >= 1) cookCV.notify_all();
    if (wood >= 3 && iron >= 1) carpenterCV.notify_all();
    if (coal >= 2 && iron >= 2) armourerCV.notify_all();
}

void Inventory::store(Resource resource) { //switch no me deja usar el unique lock xd
    if (resource == Wheat) {
        wheat++;
    } else if (resource == Coal) {
        coal++;
    } else if (resource == Wood) {
        wood++;
    } else if (resource == Iron) {
        iron++;
    }
    _notifyProducers();
}

//TENGO UN BUG, EL MINERO CAPAZ TERMINA Y ME ALCANZA LA COAL PERO EL FARMER NO TERMINO Y YO ME VOY IGUAL ARREGLAR!!!! lo mismo para el resto
bool Inventory::getCookingResources() {
    std::unique_lock<std::mutex> lock(mutexProductor);
    while ( (wheat < 2 || coal < 1) && !finishedAdding) {
        cookCV.wait(lock);
    }
    if (wheat >= 2 && coal >= 1) {
        wheat -= 2;
        coal--;
        return true;
    }
    return false;
}

bool Inventory::getCarpenterResources() {
    std::unique_lock<std::mutex> lock(mutexProductor);
    while ( (wood < 3 || iron < 1) && !finishedAdding) {
        carpenterCV.wait(lock);
    }
    if (wood >= 3 && iron >= 1) {
        wood -= 3;
        iron--;
        return true;
    }
    return false;
}

bool Inventory::getArmourerResources() {
    std::unique_lock<std::mutex> lock(mutexProductor);
    while ( (coal < 2 || iron < 2) && !finishedAdding) {
        armourerCV.wait(lock);
    }
    if (coal >= 2 && iron >= 2) {
        coal -= 2;
        iron -= 2;
        return true;
    }
    return false;
}

void Inventory::doneAdding() {
    std::unique_lock<std::mutex> l(mutexProductor);
    finishedAdding = true;
    armourerCV.notify_all();
    carpenterCV.notify_all();
    cookCV.notify_all();
}

void Inventory::printStockLeft() {
    std::cout << "Recursos restantes:\n"
                 "  - Trigo: " << wheat << "\n"
                                         "  - Madera: " << wood << "\n"
                                                                 "  - Carbon: " << coal << "\n"
                 "  - Hierro: " << iron << "\n"
                 "\n";
}

