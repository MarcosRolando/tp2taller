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
    std::vector<Gatherer*> gatherer(12);
    std::vector<std::thread*> thread(12);
    for (int i = 0; i < 12; ++i) {
        if (i < 4) {
            gatherer[i] = new Gatherer(inventory, resources[0]); //farmers
        } else if (i < 8) {
            gatherer[i] = new Gatherer(inventory, resources[1]); //lumberjacks
        } else if (i < 12) {
            gatherer[i] = new Gatherer(inventory, resources[2]); //miners
        }
        thread[i] = new std::thread(&Gatherer::work, std::ref(gatherer[i]));
    }
    for (int i = 0; i < 20; ++i) {
        resources[0].push(Wheat);
    }
    for (int i = 0; i < 30; ++i) {
        resources[1].push(Wood);
    }
    for (int i = 0; i < 50; ++i) {
        resources[2].push(Coal);
    }
    for (int i = 0; i < 70; ++i) {
        resources[2].push(Iron);
    }
    resources[0].doneAdding();
    resources[1].doneAdding();
    resources[2].doneAdding();
    for (int i = 0; i < 12; ++i) {
        thread[i]->join();
    }
    for (int i = 0; i < 12; ++i) {
        delete thread[i];
        delete gatherer[i];
    }
    inventory.print();
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
