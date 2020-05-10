#include "WorkerReader.h"
#include "ResourceReader.h"
#include "FileException.h"
#include "Gatherer.h"
#include "Inventory.h"
#include "Resource.h"
#include "BlockingQueue.h"
#include <vector>
#include <thread>

int main() {
    Inventory inventory;
    std::vector<BlockingQueue> resources(3);
    std::vector<Gatherer*> gatherer(6);
    std::vector<std::thread*> thread(6);
    for (int i = 0; i < 5; ++i) {
        if (i < 2) {
            gatherer[i] = new Gatherer(inventory, resources[0]); //farmers
        } else if (i < 4) {
            gatherer[i] = new Gatherer(inventory, resources[1]); //lumberjacks
        } else if (i < 6) {
            gatherer[i] = new Gatherer(inventory, resources[2]); //miners
        }
        thread[i] = new std::thread(&Gatherer::work, std::ref(gatherer[i]));
    }
    for (int i = 0; i < 6; ++i) {
        thread[i]->join();
    }
    for (int i = 0; i < 6; ++i) {
        delete thread[i];
        delete gatherer[i];
    }
    /*
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
     */
    return 0;
}
