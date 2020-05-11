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
