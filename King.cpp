//
// Created by marcos on 8/5/20.
//

#include "King.h"
#include "Cook.h"
#include "Carpenter.h"
#include "Armourer.h"


King::King(std::string workerFile, std::string resourceFile) : wReader(std::move(workerFile)),
                                                               rReader(std::move(resourceFile)) {
    farmerResources = nullptr;
    lumberjackResources = nullptr;
    minerResources = nullptr;
}

void King::_assignGatherers(unsigned int amount, BlockingQueue*& resources) {
    if (amount > 0) {
        resources = new BlockingQueue();
        for (unsigned i = 0; i < amount; ++i) {
            gatherers.emplace_back(inventory, *resources);
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
    _assignGatherers(wReader.getFarmerAmount(), farmerResources);
    _assignGatherers(wReader.getLumberjackAmount(), lumberjackResources);
    _assignGatherers(wReader.getMinerAmount(), minerResources);
}

void King::_spawnProducers() {
    _assignProducers(wReader.getCookAmount(), new Cook(inventory, points));
    _assignProducers(wReader.getCarpenterAmount(), new Carpenter(inventory, points));
    _assignProducers(wReader.getArmourerAmount(), new Armourer(inventory, points));
}

void King::_sendResource(char resource) {
    switch (resource) {
        case 'T':
            if (farmerResources != nullptr) farmerResources->push(Wheat);
            break;
        case 'M':
            if (farmerResources != nullptr) farmerResources->push(Wood);
            break;
        case 'C':
            if (farmerResources != nullptr) farmerResources->push(Coal);
            break;
        case 'H':
            if (farmerResources != nullptr) farmerResources->push(Iron);
    }
}

void King::runKingdom() {
    char resource;
    _spawnGatherers();
    _spawnProducers();
    //disparo los threads
    resource = rReader.readResource();
    while (resource != 0) {
        _sendResource(resource);
        resource = rReader.readResource();
    }
    //joineo los recolectores
    inventory.doneAdding();
    //joineo los productores
    points.printPoints();
}

King::~King() {
    delete farmerResources;
    delete lumberjackResources;
    delete minerResources;
}


