//
// Created by marcos on 11/5/20.
//

#include "Cook.h"
#include <unistd.h>

void Cook::work() {
    while (inventory.getCookingResources()) {
        usleep(60000);
        points.incrementPoints(5);
    }
}

void Cook::run() {
    work();
}
