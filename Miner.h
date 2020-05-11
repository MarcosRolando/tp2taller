//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_MINER_H
#define TP2TALLER_MINER_H

#include "Gatherer.h"

class Miner : public Gatherer {
public:
    Miner(Inventory& inventory, BlockingQueue& resources) :
            Gatherer(inventory, resources) {};
    void work();
};


#endif //TP2TALLER_MINER_H
