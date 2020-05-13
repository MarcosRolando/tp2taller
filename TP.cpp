//
// Created by marcos on 12/5/20.
//

#include "TP.h"

bool TP::_validInput(int argc) {
    if (argc != 3) {
        std::cerr << "La cantidad de argumentos es invalida:"
                     " ./tp archivoTrabajadores archivoMapa" << std::endl;
        return false;
    }
    return true;
}

int TP::run(int argc, char** argv) {
    if (!_validInput(argc)) return 1;
    try {
        King king(argv[1], argv[2]);
        king.runKingdom();
    } catch (FileException& e) {
        e.printError();
        return 1;
    }
    return 0;
}
