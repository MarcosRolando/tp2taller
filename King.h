//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_KING_H
#define TP2TALLER_KING_H

#include "WorkerReader.h"
#include "ResourceReader.h"
#include "Gatherer.h"
#include "Producer.h"
#include "Inventory.h"
#include "BenefitPoints.h"

class King {
private:
    WorkerReader wReader;
    ResourceReader rReader;
    Inventory inventory;
    BenefitPoints points;
    BlockingQueue *farmerResources, *lumberjackResources, *minerResources;
    std::vector<Gatherer> gatherers;
    std::vector<Producer*> producers;
public:
    King(std::string workerFile, std::string resourceFile);
    void runKingdom(); //seria el Run del rey pero es un nombre mas epico
    ~King();
private:
    void _spawnGatherers();
    void _assignGatherers(unsigned int amount, BlockingQueue*& resources);
    void _spawnProducers();
    void _spawnCooks();
    void _spawnCarpenters();
    void _spawnArmourers();
    void _sendResource(char resource);
};


#endif //TP2TALLER_KING_H
