//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_COOK_H
#define TP2TALLER_COOK_H

#include "Inventory.h"
#include "BenefitPoints.h"

class Cook {
private:
    Inventory& inventory;
    BenefitPoints& points;
public:
    Cook(Inventory& inventory, BenefitPoints& points) :
                                    inventory(inventory), points(points) {};
    void work();
};


#endif //TP2TALLER_COOK_H
