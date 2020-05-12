//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_GATHERER_H
#define TP2TALLER_GATHERER_H

#include "Inventory.h"
#include "BlockingQueue.h"
#include "Thread.h"

class Gatherer : public Thread {
private:
    Inventory& inventory;
    BlockingQueue& resources;
public:
    Gatherer(Inventory& inventory, BlockingQueue& resources) :
                                inventory(inventory), resources(resources) {};
    void work();
private:
    void run() override;
};


#endif //TP2TALLER_GATHERER_H
