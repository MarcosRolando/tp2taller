//
// Created by marcos on 12/5/20.
//

#ifndef TP2TALLER_PRODUCER_H
#define TP2TALLER_PRODUCER_H

#include "Inventory.h"
#include "BenefitPoints.h"

class Producer {
protected:
    Inventory& inventory;
    BenefitPoints& points;
public:
    Producer(Inventory& inventory, BenefitPoints& points) : inventory(inventory),
                                                             points(points) {};
    virtual void work() = 0;
    virtual ~Producer() = default;
};


#endif //TP2TALLER_PRODUCER_H
