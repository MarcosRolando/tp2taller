//
// Created by marcos on 7/5/20.
//

#include "WorkerReader.h"
#include "FileException.h"

WorkerReader::WorkerReader(std::string workersFile) :
            workersName(workersFile), workersFile(workersFile) {
    if (!this->workersFile.is_open())
        throw FileException(workersFile, NONEXISTENT_FILE);
    armourerAmount = -1;
    carpenterAmount = -1;
    cookAmount = -1;
    minerAmount = -1;
    lumberjackAmount = -1;
    farmerAmount = -1;
}

void WorkerReader::readWorkers() {
    std::string worker, sAmount;
    int amount;
    while (!workersFile.eof()) {
        std::getline(workersFile, worker, '=');
        std::getline(workersFile, sAmount);
        try {
            amount = std::stoi(sAmount);
        } catch (std::invalid_argument& e) {
            throw FileException(workersName, BAD_FILE);
        }
        if (!workersFile.eof()) _processWorker(worker, amount);
    }
    if (!_validWorkerAmount()) throw FileException(workersName,
                                                            BAD_FILE);
}

bool WorkerReader::_validWorkerAmount() const {
    return !(farmerAmount < 0 || lumberjackAmount < 0 || minerAmount < 0 ||
             cookAmount < 0 || carpenterAmount < 0 || armourerAmount < 0);
}

void WorkerReader::_processWorker(const std::string& worker, int amount) {
    if (worker == "Agricultores") farmerAmount = amount;
    else if (worker == "Leniadores") lumberjackAmount = amount;
    else if (worker == "Mineros") minerAmount = amount;
    else if (worker == "Cocineros") cookAmount = amount;
    else if (worker == "Carpinteros") carpenterAmount = amount;
    else if (worker == "Armeros") armourerAmount = amount;
    else throw FileException(workersName, BAD_FILE);
}

int WorkerReader::getFarmerAmount() const {
    return farmerAmount;
}

int WorkerReader::getLumberjackAmount() const {
    return lumberjackAmount;
}

int WorkerReader::getMinerAmount() const {
    return minerAmount;
}

int WorkerReader::getCookAmount() const {
    return cookAmount;
}

int WorkerReader::getCarpenterAmount() const {
    return carpenterAmount;
}

int WorkerReader::getArmourerAmount() const {
    return armourerAmount;
}
