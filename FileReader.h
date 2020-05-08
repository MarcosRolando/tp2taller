//
// Created by marcos on 7/5/20.
//

#ifndef TP2TALLER_FILEREADER_H
#define TP2TALLER_FILEREADER_H

#include <iostream>
#include <fstream>

class FileReader {
private:
    std::ifstream workersFile;
public:
    explicit FileReader(std::string workersFile);
};


#endif //TP2TALLER_FILEREADER_H
