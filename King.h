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
    std::vector<Gatherer> gatherers;
    std::vector<Producer*> producers;
    std::vector<BlockingQueue*> resources;
public:
    King(std::string workerFile, std::string resourceFile) : wReader(std::move(workerFile)),
                                            rReader(std::move(resourceFile)) {};
    void runKingdom(); //seria el Run del rey pero es un nombre mas epico
private:
    void _spawnGatherers();
    void _assignGatherers(unsigned int amount);
    void _spawnProducers();
    void _assignCooks();
    void _assignCarpenters();
    void _assignArmourers();
};


#endif //TP2TALLER_KING_H
