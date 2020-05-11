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
    finishedFarmer = false;
    finishedLumberjack = false;
    finishedMiner = false;
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

bool Inventory::getCookingResources() {
    std::unique_lock<std::mutex> lock(mutexProductor);
    while ( (wheat < 2 || coal < 1) && !finishedFarmer && ! finishedMiner) {
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
    while ( (wood < 3 || iron < 1) && !finishedLumberjack && ! finishedMiner) {
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
    while ( (coal < 2 || iron < 2) && !finishedMiner) {
        armourerCV.wait(lock);
    }
    if (coal >= 2 && iron >= 2) {
        coal -= 2;
        iron -= 2;
        return true;
    }
    return false;
}

void Inventory::farmerFinished() {
    std::unique_lock<std::mutex> l(mutexProductor);
    finishedFarmer = true;
    cookCV.notify_all();
}

void Inventory::lumberjackFinished() {
    std::unique_lock<std::mutex> l(mutexProductor);
    finishedLumberjack = true;
    carpenterCV.notify_all();
}

void Inventory::minerFinished() {
    std::unique_lock<std::mutex> l(mutexProductor);
    finishedMiner = true;
    cookCV.notify_all();
    carpenterCV.notify_all();
    armourerCV.notify_all();
}

/*
void Inventory::print() {
    std::cout << "Wheat: " << wheat << std::endl;
    std::cout << "Wood: " << wood << std::endl;
    std::cout << "Coal: " << coal << std::endl;
    std::cout << "Iron: " << iron << std::endl;
}
*/
