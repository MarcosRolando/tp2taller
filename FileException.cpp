//
// Created by marcos on 8/5/20.
//

#include "FileException.h"
#include <iostream>

void FileException::printError() {
    switch (eType) {
        case NONEXISTENT_FILE:
            std::cout << "El archivo " << fileName << " no existe, asegurese que "
                                                            "esta en el directorio del"
                                                            " ejecutable" << std::endl;
            break;
        case BAD_FILE:
            std::cout << "El archivo " << fileName << " no tiene los "
                                                            "parametros necesar"
                                                            "ios" << std::endl;
            break;
    }
}
