#include "FileReader.h"
#include "NonExistentFileException.h"

int main() {
    try {
        FileReader reader("trabajadores.cfg", "mapa.txt");
        reader.readWorkers();
    } catch (NonExistentFileException& e) {
        e.printError();
    }
    return 0;
}
