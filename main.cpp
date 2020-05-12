#include "King.h"
#include "FileException.h"
int main(int arc, char** argv) {
    try {
        King king("trabajadores.cfg", "mapa.txt");
        king.runKingdom();
    } catch (FileException& e) {
        e.printError();
        return 1;
    }
    return 0;
}
