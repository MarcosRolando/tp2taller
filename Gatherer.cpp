//
// Created by marcos on 8/5/20.
//

#include "Gatherer.h"
#include <unistd.h>
#include "Resource.h"

void Gatherer::work() {
    while (!resources.empty()) {
        Resource resource = resources.pop();
        if (resource != Mud) {
            usleep(50000);
            inventory.store(resource);
        }
    }
}
