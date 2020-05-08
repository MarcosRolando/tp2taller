//
// Created by marcos on 7/5/20.
//

#include "WorkerReader.h"
#include "FileException.h"

WorkerReader::WorkerReader(std::string workersFile) :
            workersName(workersFile), workersFile(workersFile) {
    if (!this->workersFile.is_open())
        throw FileException(workersFile, NONEXISTENT_FILE);
    this->armourerAmount = -1;
    this->carpenterAmount = -1;
    this->cookAmount = -1;
    this->minerAmount = -1;
    this->lumberjackAmount = -1;
    this->farmerAmount = -1;
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
            throw FileException(this->workersName, BAD_FILE);
        }
        if (!workersFile.eof()) _processWorker(worker, amount);
    }
    if (!_validWorkerAmount()) throw FileException(this->workersName,
                                                            BAD_FILE);
}

bool WorkerReader::_validWorkerAmount() const {
    return !(farmerAmount < 0 || lumberjackAmount < 0 || minerAmount < 0 ||
             cookAmount < 0 || carpenterAmount < 0 || armourerAmount < 0);
}

void WorkerReader::_processWorker(const std::string& worker, int amount) {
    if (worker == "Agricultores") this->farmerAmount = amount;
    else if (worker == "Leniadores") this->lumberjackAmount = amount;
    else if (worker == "Mineros") this->minerAmount = amount;
    else if (worker == "Cocineros") this->cookAmount = amount;
    else if (worker == "Carpinteros") this->carpenterAmount = amount;
    else if (worker == "Armeros") this->armourerAmount = amount;
    else throw FileException(this->workersName, BAD_FILE);
}

int WorkerReader::getFarmerAmount() {
    return this->farmerAmount;
}

int WorkerReader::getLumberjackAmount() {
    return this->lumberjackAmount;
}

int WorkerReader::getMinerAmount() {
    return this->minerAmount;
}

int WorkerReader::getCookAmount() {
    return this->cookAmount;
}

int WorkerReader::getCarpenterAmount() {
    return this->carpenterAmount;
}

int WorkerReader::getArmourerAmount() {
    return this->armourerAmount;
}
