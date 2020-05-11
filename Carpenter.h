//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_CARPENTER_H
#define TP2TALLER_CARPENTER_H

#include "Inventory.h"
#include "BenefitPoints.h"

class Carpenter {
private:
    Inventory& inventory;
    BenefitPoints& points;
public:
    Carpenter(Inventory& inventory, BenefitPoints& points) :
                                    inventory(inventory), points(points) {};
    void work();
};


#endif //TP2TALLER_CARPENTER_H
