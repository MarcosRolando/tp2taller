//
// Created by marcos on 8/5/20.
//

#include "King.h"
#include "Cook.h"
#include "Carpenter.h"
#include "Armourer.h"

void King::_assignGatherers(unsigned int amount) {
    if (amount > 0) {
        resources.emplace_back(new BlockingQueue());
        for (unsigned i = 0; i < amount; ++i) {
            gatherers.emplace_back(inventory, *resources.back());
        }
    }
}

void King::_assignCooks() {
    unsigned int amount = wReader.getCookAmount();
    if (amount > 0) {
        for (unsigned i = 0; i < amount; ++i) {
            producers.emplace_back(new Cook(inventory, points));
        }
    }
}

void King::_assignCarpenters() {
    unsigned int amount = wReader.getCarpenterAmount();
    if (amount > 0) {
        for (unsigned i = 0; i < amount; ++i) {
            producers.emplace_back(new Carpenter(inventory, points));
        }
    }
}

void King::_assignArmourers() {
    unsigned int amount = wReader.getArmourerAmount();
    if (amount > 0) {
        for (unsigned i = 0; i < amount; ++i) {
            producers.emplace_back(new Armourer(inventory, points));
        }
    }
}

void King::_spawnGatherers() {
    _assignGatherers(wReader.getFarmerAmount());
    _assignGatherers(wReader.getLumberjackAmount());
    _assignGatherers(wReader.getMinerAmount());
}

void King::_spawnProducers() {
    _assignCooks();
    _assignCarpenters();
    _assignArmourers();
}

void King::runKingdom() {
    _spawnGatherers();
    _spawnProducers();

}

