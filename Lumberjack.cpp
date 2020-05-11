//
// Created by marcos on 11/5/20.
//

#include "Lumberjack.h"

void Lumberjack::work() {
    Gatherer::work();
    inventory.lumberjackFinished();
}