//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_FARMER_H
#define TP2TALLER_FARMER_H

#include "Gatherer.h"

class Farmer : public Gatherer {
public:
    Farmer(Inventory& inventory, BlockingQueue& resources) :
                                        Gatherer(inventory, resources) {};
    void work();
};


#endif //TP2TALLER_FARMER_H
