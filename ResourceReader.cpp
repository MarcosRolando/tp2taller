//
// Created by marcos on 8/5/20.
//

#include "ResourceReader.h"
#include "FileException.h"

ResourceReader::ResourceReader(std::string resourceFile) : resourceFile(resourceFile) {
    if (!this->resourceFile.is_open())
        throw FileException(resourceFile, NONEXISTENT_FILE);
    this->length = 0;
    this->position = 0;
}

char ResourceReader::readResource() {
    if (!resourceFile.eof() || (this->position < this->length)) {
        if (!(this->position < this->length)){
            std::getline(this->resourceFile, this->resources);
            this->length = resources.length();
            this->position = 0;
        }
        char resource = resources[position];
        this->position++;
        return resource;
    } else {
        return 0;
    }
}

