//
// Created by marcos on 11/5/20.
//

#include "Miner.h"

void Miner::work() {
    Gatherer::work();
    inventory.minerFinished();
}