//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_INVENTORY_H
#define TP2TALLER_INVENTORY_H

#include "Resource.h"
#include <mutex>
#include <condition_variable>
#include <atomic>

class Inventory {
private:
    std::atomic_uint wheat, coal, wood, iron;
    std::atomic_bool finishedFarmer, finishedLumberjack, finishedMiner;
    std::mutex mutexProductor;
    std::condition_variable cookCV, carpenterCV, armourerCV;
public:
    Inventory();
    void store(Resource resource);
    bool getCookingResources();
    bool getCarpenterResources();
    bool getArmourerResources();
    //void print();
private:
    void _notifyProducers();
};


#endif //TP2TALLER_INVENTORY_H
