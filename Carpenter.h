//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_CARPENTER_H
#define TP2TALLER_CARPENTER_H

#include "Inventory.h"

class Carpenter {
private:
    Inventory& inventory;
public:
    explicit Carpenter(Inventory& inventory) : inventory(inventory) {};
    void work();
};


#endif //TP2TALLER_CARPENTER_H
