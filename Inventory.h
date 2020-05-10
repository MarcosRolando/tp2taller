//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_INVENTORY_H
#define TP2TALLER_INVENTORY_H

#include "Resource.h"
#include <mutex>
#include <condition_variable>

class Inventory {
private:
    unsigned int wheat, coal, wood, iron;
    std::mutex wheatMtx, coalMtx, woodMtx, ironMtx;
public:
    Inventory();
    void store(Resource resource);
    void print();
};


#endif //TP2TALLER_INVENTORY_H
