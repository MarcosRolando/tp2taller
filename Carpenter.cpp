//
// Created by marcos on 11/5/20.
//

#include "Carpenter.h"
#include <unistd.h>

void Carpenter::work() {
    while (inventory.getCarpenterResources()) {
        usleep(60000);
        points.incrementPoints(2);
    }
}

void Carpenter::run() {
    work();
}

Producer *Carpenter::newCarpenter(Inventory &inventory, BenefitPoints &points) {
    return new Carpenter(inventory, points);
}
