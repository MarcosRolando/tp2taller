//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_NONEXISTENTFILEEXCEPTION_H
#define TP2TALLER_NONEXISTENTFILEEXCEPTION_H

#include <exception>
#include <iostream>

class NonExistentFileException : public std::exception {
private:
    std::string fileName;
public:
    explicit NonExistentFileException(std::string fileName) : fileName(fileName)
                                                                            {};
    void printError();
};


#endif //TP2TALLER_NONEXISTENTFILEEXCEPTION_H
