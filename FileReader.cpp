//
// Created by marcos on 7/5/20.
//

#include "FileReader.h"
#include "FileException.h"

FileReader::FileReader(std::string workersFile, std::string resourcesFile) :
            workersName(workersFile), resourcesName(resourcesFile),
            workersFile(workersFile), resourcesFile(resourcesFile) {
    if (!this->workersFile.is_open())
        throw FileException(workersFile, NONEXISTENT_FILE);
    else if (!this->resourcesFile.is_open())
        throw FileException(resourcesFile, NONEXISTENT_FILE);
    this->armourerAmount = -1;
    this->carpenterAmount = -1;
    this->cookAmount = -1;
    this->minerAmount = -1;
    this->lumberjackAmount = -1;
    this->farmerAmount = -1;
}

void FileReader::readWorkers() {
    std::string worker, sAmount;
    int amount;
    while (!workersFile.eof()) {
        std::getline(workersFile, worker, '=');
        std::getline(workersFile, sAmount);
        try {
            amount = std::stoi(sAmount);
        } catch (std::invalid_argument& e) {
            throw FileException(this->workersName, BAD_FILE);
        }
        if (!workersFile.eof()) _processWorker(worker, amount);
    }
    if (!_validWorkerAmount()) throw FileException(this->workersName,
                                                            BAD_FILE);
}

bool FileReader::_validWorkerAmount() {
    return !(farmerAmount < 0 || lumberjackAmount < 0 || minerAmount < 0 ||
             cookAmount < 0 || carpenterAmount < 0 || armourerAmount < 0);
}

void FileReader::_processWorker(std::string& worker, int amount) {
    if (worker == "Agricultores") this->farmerAmount = amount;
    else if (worker == "Leniadores") this->lumberjackAmount = amount;
    else if (worker == "Mineros") this->minerAmount = amount;
    else if (worker == "Cocineros") this->cookAmount = amount;
    else if (worker == "Carpinteros") this->carpenterAmount = amount;
    else if (worker == "Armeros") this->armourerAmount = amount;
    else throw FileException(this->workersName, BAD_FILE);
}
