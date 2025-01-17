//
// Created by marcos on 7/5/20.
//

#ifndef TP2TALLER_WORKERREADER_H
#define TP2TALLER_WORKERREADER_H

#include <fstream>

class WorkerReader {
private:
    std::string workersName;
    std::ifstream workersFile;
    int farmerAmount, lumberjackAmount, minerAmount;
    int cookAmount, carpenterAmount, armourerAmount;
public:
    explicit WorkerReader(std::string workersFile);
    void readWorkers();
    int getFarmerAmount() const;
    int getLumberjackAmount() const;
    int getMinerAmount() const;
    int getCookAmount() const;
    int getCarpenterAmount() const;
    int getArmourerAmount() const;

private:
    bool _validWorkerAmount() const;
    void _processWorker(const std::string& worker, int amount);
};


#endif //TP2TALLER_WORKERREADER_H
