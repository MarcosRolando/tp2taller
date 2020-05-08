//
// Created by marcos on 7/5/20.
//

#include "FileReader.h"

FileReader::FileReader(std::string workersFile) : workersFile(workersFile) {
    if (!this->workersFile.is_open()) throw std::exception();
}
