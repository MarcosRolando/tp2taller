//
// Created by marcos on 8/5/20.
//

#include "NonExistentFileException.h"
#include <iostream>

void NonExistentFileException::printError() {
    std::cout << "El archivo " << this->fileName << " no existe, asegurese que "
                                                    "esta en el directorio del"
                                                    " ejecutable" << std::endl;
}
