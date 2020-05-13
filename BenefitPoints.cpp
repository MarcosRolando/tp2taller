//
// Created by marcos on 11/5/20.
//

#include "BenefitPoints.h"

void BenefitPoints::incrementPoints(unsigned int newPoints) {
    points += newPoints;
}

void BenefitPoints::printPoints() {
    std::cout << "Puntos de Beneficio acumulados: " << points << "\n";
}


