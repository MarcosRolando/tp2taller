#include "WorkerReader.h"
#include "ResourceReader.h"
#include "FileException.h"

int main() {
    try {
        WorkerReader wReader("trabajadores.cfg");
        wReader.readWorkers();
        ResourceReader rReader("mapa.txt");
        char c = 1;
        while (c != 0) {
            c = rReader.readResource();
            std::cout << c << std::endl;
        }
    } catch (FileException& e) {
        e.printError();
    }
    return 0;
}
