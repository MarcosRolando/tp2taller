//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_ARMOURER_H
#define TP2TALLER_ARMOURER_H

#include "Inventory.h"
#include "BenefitPoints.h"

class Armourer {
private:
    Inventory& inventory;
    BenefitPoints& points;
public:
    Armourer(Inventory& inventory, BenefitPoints& points) :
                                    inventory(inventory), points(points) {};
    void work();
};


#endif //TP2TALLER_ARMOURER_H
