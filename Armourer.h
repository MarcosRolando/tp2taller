//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_ARMOURER_H
#define TP2TALLER_ARMOURER_H

#include "Inventory.h"
#include "BenefitPoints.h"
#include "Producer.h"

class Armourer : public Producer {
public:
    Armourer(Inventory& inventory, BenefitPoints& points) :
                                    Producer(inventory, points) {};
    void work() override;
private:
    void run() override;
};


#endif //TP2TALLER_ARMOURER_H
