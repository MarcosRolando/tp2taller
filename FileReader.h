//
// Created by marcos on 7/5/20.
//

#ifndef TP2TALLER_FILEREADER_H
#define TP2TALLER_FILEREADER_H

#include <iostream>
#include <fstream>

class FileReader {
private:
    std::ifstream workersFile, resourcesFile;
    unsigned int farmerAmount, lumberjackAmount, minerAmount;
    unsigned int cookAmount, carpenterAmount, armourerAmount;
public:
    FileReader(std::string workersFile, std::string resourcesFile);
    void readWorkers();
private:
    void _processWorker(std::string& worker, size_t amount);
};


#endif //TP2TALLER_FILEREADER_H
