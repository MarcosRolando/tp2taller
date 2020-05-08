//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_FILEEXCEPTION_H
#define TP2TALLER_FILEEXCEPTION_H

#include <exception>
#include <iostream>

const int NONEXISTENT_FILE = 1;
const int BAD_FILE = 2;

class FileException : public std::exception {
private:
    std::string fileName;
    int eType;
public:
    explicit FileException(std::string fileName, int e) : fileName(fileName),
                                                            eType(e) {};
    void printError();
};


#endif //TP2TALLER_FILEEXCEPTION_H
