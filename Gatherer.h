//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_GATHERER_H
#define TP2TALLER_GATHERER_H

#include "Inventory.h"
#include "BlockingQueue.h"

class Gatherer {
protected:
    Inventory& inventory;
private:
    BlockingQueue& resources;
public:
    Gatherer(Inventory& inventory, BlockingQueue& resources) :
                                inventory(inventory), resources(resources) {};
    void work();
    virtual ~Gatherer() = default;
};


#endif //TP2TALLER_GATHERER_H
