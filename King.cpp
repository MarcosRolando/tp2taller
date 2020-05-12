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

void King::_assignProducers(unsigned int amount, Producer* producer) {
    if (amount > 0) {
        for (unsigned i = 0; i < amount; ++i) {
            producers.emplace_back(producer);
        }
    }
}

void King::_spawnGatherers() {
    _assignGatherers(wReader.getFarmerAmount());
    _assignGatherers(wReader.getLumberjackAmount());
    _assignGatherers(wReader.getMinerAmount());
}

void King::_spawnProducers() {
    _assignProducers(wReader.getCookAmount(), new Cook(inventory, points));
    _assignProducers(wReader.getCarpenterAmount(), new Carpenter(inventory, points));
    _assignProducers(wReader.getArmourerAmount(), new Armourer(inventory, points));
}

void King::runKingdom() {
    _spawnGatherers();
    _spawnProducers();

}

