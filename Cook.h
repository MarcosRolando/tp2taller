//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_COOK_H
#define TP2TALLER_COOK_H

#include "Inventory.h"

class Cook {
private:
    Inventory& inventory;
public:
    explicit Cook(Inventory& inventory) : inventory(inventory) {};
    void work();
};


#endif //TP2TALLER_COOK_H
