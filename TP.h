//
// Created by marcos on 12/5/20.
//

#ifndef TP2TALLER_TP_H
#define TP2TALLER_TP_H

#include "King.h"
#include "FileException.h"

class TP {
public:
    static int run(int argc, char** argv);
private:
    static bool _validInput(int argc);
};


#endif //TP2TALLER_TP_H
