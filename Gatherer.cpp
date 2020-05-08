//
// Created by marcos on 8/5/20.
//

#include "Gatherer.h"
#include <unistd.h>

void Gatherer::work() {
    while (!resources.empty()) {
        Resource* resource = resources.pop();
        if (resource != nullptr) {
            usleep(50);
            inventory.store(resource);
        }
    }
}
