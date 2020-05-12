//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_CARPENTER_H
#define TP2TALLER_CARPENTER_H

#include "Inventory.h"
#include "BenefitPoints.h"
#include "Producer.h"

class Carpenter : public Producer {
public:
    Carpenter(Inventory& inventory, BenefitPoints& points) :
                                    Producer(inventory, points) {};
    void work() override;
    static Producer* newCarpenter(Inventory& inventory, BenefitPoints& points);
private:
    void run() override;
};


#endif //TP2TALLER_CARPENTER_H
