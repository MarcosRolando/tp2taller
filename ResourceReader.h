//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_RESOURCEREADER_H
#define TP2TALLER_RESOURCEREADER_H

#include <fstream>

class ResourceReader {
private:
    std::ifstream resourceFile;
    std::string resources; //los recursos de la linea leida
    int length, position;
public:
    explicit ResourceReader(std::string resourceFile);
    char readResource();
};


#endif //TP2TALLER_RESOURCEREADER_H
