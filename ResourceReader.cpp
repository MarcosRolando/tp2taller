//
// Created by marcos on 8/5/20.
//

#include "ResourceReader.h"
#include "FileException.h"

ResourceReader::ResourceReader(std::string resourceFile) : resourceFile(resourceFile) {
    if (!this->resourceFile.is_open())
        throw FileException(resourceFile, NONEXISTENT_FILE);
    length = 0;
    position = 0;
}

char ResourceReader::readResource() {
    if (!resourceFile.eof() || (position < length)) {
        if (position >= length){
            std::getline(resourceFile, resources);
            length = resources.length();
            position = 0;
        }
        char resource = resources[position];
        position++;
        return resource;
    } else {
        return 0;
    }
}

