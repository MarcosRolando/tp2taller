//
// Created by marcos on 11/5/20.
//

#ifndef TP2TALLER_BENEFITPOINTS_H
#define TP2TALLER_BENEFITPOINTS_H

#include <atomic>
#include <iostream>

class BenefitPoints {
private:
    std::atomic_uint points;
public:
    BenefitPoints() : points(0) {};
    void incrementPoints(unsigned int newPoints);
    void printPoints();
};


#endif //TP2TALLER_BENEFITPOINTS_H
