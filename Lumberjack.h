//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_LUMBERJACK_H
#define TP2TALLER_LUMBERJACK_H

#include "Gatherer.h"

class Lumberjack : public Gatherer {
public:
    Lumberjack(Inventory& inventory, BlockingQueue& resources) :
                                        Gatherer(inventory, resources) {};
};


#endif //TP2TALLER_LUMBERJACK_H