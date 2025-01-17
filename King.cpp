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

void King::_assignProducers(unsigned int amount, Producer* (*f) (Inventory&, BenefitPoints&)) {
    if (amount > 0) {
        for (unsigned i = 0; i < amount; ++i) {
            producers.emplace_back(f(inventory, points));
        }
    }
}

void King::_spawnGatherers() {
    _assignGatherers(wReader.getFarmerAmount(), farmerResources);
    _assignGatherers(wReader.getLumberjackAmount(), lumberjackResources);
    _assignGatherers(wReader.getMinerAmount(), minerResources);
}

void King::_spawnProducers() {
    _assignProducers(wReader.getCookAmount(), Cook::newCook);
    _assignProducers(wReader.getCarpenterAmount(), Carpenter::newCarpenter);
    _assignProducers(wReader.getArmourerAmount(), Armourer::newArmourer);
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

void King::_runPeasants() {
    wReader.readWorkers();
    _spawnGatherers();
    _spawnProducers();
    for (auto & gatherer : gatherers) {
        gatherer.start();
    }
    for (auto & producer : producers) {
        producer->start();
    }
}

void King::_sendResources() {\
    char resource;
    resource = rReader.readResource();
    while (resource != 0) {
        _sendResource(resource);
        resource = rReader.readResource();
    }
    if (farmerResources != nullptr) farmerResources->doneAdding();
    if (lumberjackResources != nullptr) lumberjackResources->doneAdding();
    if (minerResources != nullptr) minerResources->doneAdding();
}

void King::runKingdom() {
    _runPeasants();
    _sendResources();
    for (auto & gatherer : gatherers) {
        gatherer.join();
    }
    inventory.doneAdding();
    for (auto & producer : producers) {
        producer->join();
    }
    inventory.printStockLeft();
    points.printPoints();
}

King::~King() {
    for (auto & producer : producers) {
        delete producer;
    }
    delete farmerResources;
    delete lumberjackResources;
    delete minerResources;
}



