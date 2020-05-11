//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_ARMOURER_H
#define TP2TALLER_ARMOURER_H

#include "Inventory.h"

class Armourer {
private:
    Inventory& inventory;
public:
    explicit Armourer(Inventory& inventory) : inventory(inventory) {};
    void work();
};


#endif //TP2TALLER_ARMOURER_H
