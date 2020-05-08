#include "FileReader.h"
#include "FileException.h"

int main() {
    try {
        FileReader reader("trabajadores.cfg", "mapa.txt");
        reader.readWorkers();
    } catch (FileException& e) {
        e.printError();
    }
    return 0;
}
