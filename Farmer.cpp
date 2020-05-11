//
// Created by marcos on 11/5/20.
//

#include "Farmer.h"

void Farmer::work() {
    Gatherer::work();
    inventory.farmerFinished();
}
