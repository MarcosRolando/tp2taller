//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_COOK_H
#define TP2TALLER_COOK_H

#include "Inventory.h"
#include "BenefitPoints.h"
#include "Producer.h"

class Cook : public Producer {
public:
    Cook(Inventory& inventory, BenefitPoints& points) :
                                    Producer(inventory, points) {};
    void work();
};


#endif //TP2TALLER_COOK_H
