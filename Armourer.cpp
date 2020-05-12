//
// Created by marcos on 11/5/20.
//

#include "Armourer.h"
#include <unistd.h>

void Armourer::work() {
    while (inventory.getArmourerResources()) {
        usleep(60000);
        points.incrementPoints(3);
    }
}

void Armourer::run() {
    work();
}

Producer* Armourer::newArmourer(Inventory& inventory, BenefitPoints& points) {
    return new Armourer(inventory, points);
}
