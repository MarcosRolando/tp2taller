//
// Created by marcos on 7/5/20.
//

#include "FileReader.h"
#include "NonExistentFileException.h"

FileReader::FileReader(std::string workersFile, std::string resourcesFile) :
            workersFile(workersFile), resourcesFile(resourcesFile) {
    if (!this->workersFile.is_open())
        throw NonExistentFileException(workersFile);
    else if (!this->resourcesFile.is_open())
        throw NonExistentFileException(resourcesFile);
}

void FileReader::readWorkers() {
    std::string worker, sAmount;
    unsigned int amount;
    while (!workersFile.eof()) {
        std::getline(workersFile, worker, '=');
        std::getline(workersFile, sAmount);
        amount = std::stoi(sAmount);
        _processWorker(worker, amount);
    }
}

void FileReader::_processWorker(std::string& worker, size_t amount) {
    if (worker == "Agricultores") this->farmerAmount = amount;
    else if (worker == "Leniadores") this->lumberjackAmount = amount;
    else if (worker == "Mineros") this->minerAmount = amount;
    else if (worker == "Cocineros") this->cookAmount = amount;
    else if (worker == "Carpinteros") this->carpenterAmount = amount;
    else if (worker == "Armeros") this->armourerAmount = amount;
}
