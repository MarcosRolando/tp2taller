//
// Created by marcos on 7/5/20.
//

#ifndef TP2TALLER_FILEREADER_H
#define TP2TALLER_FILEREADER_H

#include <iostream>
#include <fstream>

class FileReader {
private:
    std::string workersName, resourcesName;
    std::ifstream workersFile, resourcesFile;
    int farmerAmount, lumberjackAmount, minerAmount;
    int cookAmount, carpenterAmount, armourerAmount;
public:
    FileReader(std::string workersFile, std::string resourcesFile);
    void readWorkers();
private:
    bool _validWorkerAmount() const;
    void _processWorker(const std::string& worker, int amount);
};


#endif //TP2TALLER_FILEREADER_H
