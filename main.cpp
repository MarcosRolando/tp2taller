#include "WorkerReader.h"
#include "ResourceReader.h"
#include "FileException.h"
/*
#include "Gatherer.h"
#include "Inventory.h"
#include "Resource.h"
#include "BlockingQueue.h"
#include <vector>
#include <thread>
#include "Cook.h"
#include "Carpenter.h"
#include "Armourer.h"
#include "BenefitPoints.h"
*/
#include "King.h"
int main(int arc, char** argv) {
    King king("trabajadores.cfg", "mapa.txt");
    king.runKingdom();
    /*
    Inventory inventory;
    BenefitPoints points;
    std::vector<BlockingQueue> resources(3);
    std::vector<Gatherer*> gatherer(6);
    std::vector<Cook*> cook(1);
    std::vector<Carpenter*> carpenter(3);
    std::vector<Armourer*> armourer(1);
    std::vector<std::thread*> thread(11);
    for (int i = 0; i < 2; ++i) {
        gatherer[i] = new Gatherer(inventory, resources[0]); //farmers
        thread[i] = new std::thread(&Gatherer::work, std::ref(gatherer[i]));
    }
    for (int i = 2; i < 3; ++i) {
        gatherer[i] = new Gatherer(inventory, resources[1]); //lumberjacks
        thread[i] = new std::thread(&Gatherer::work, std::ref(gatherer[i]));
    }
    for (int i = 3; i < 6; ++i) {
        gatherer[i] = new Gatherer(inventory, resources[2]); //miners
        thread[i] = new std::thread(&Gatherer::work, std::ref(gatherer[i]));
    }
    cook[0] = new Cook(inventory, points);
    thread[6] = new std::thread(&Cook::work, std::ref(cook[0]));
    for (int i = 0; i < 3; ++i) {
        carpenter[i] = new Carpenter(inventory, points);
        thread[i+7] = new std::thread(&Carpenter::work, std::ref(carpenter[i]));
    }
    armourer[0] = new Armourer(inventory, points);
    thread[10] = new std::thread(&Armourer::work, std::ref(armourer[0]));
    resources[0].push(Wheat);
    resources[0].push(Wheat);
    resources[0].push(Wheat);
    resources[1].push(Wood);
    resources[2].push(Coal);
    resources[2].push(Iron);
    resources[2].push(Iron);
    resources[2].push(Iron);
    resources[2].push(Coal);
    resources[0].push(Wheat);
    resources[0].push(Wheat);
    resources[0].push(Wheat);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[2].push(Coal);
    resources[2].push(Coal);
    resources[2].push(Coal);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[1].push(Wood);
    resources[0].doneAdding();
    resources[1].doneAdding();
    resources[2].doneAdding();
    for (int i = 0; i < 6; ++i) {
        thread[i]->join();
    }
    inventory.doneAdding();
    for (int i = 6; i < 11; ++i) {
        thread[i]->join();
    }
    for (int i = 0; i < 6; ++i) {
        delete gatherer[i];
    }
    delete cook[0];
    for (int i = 0; i < 3; ++i) {
        delete carpenter[i];
    }
    delete armourer[0];
    for (int i = 0; i < 11; ++i) {
        delete thread[i];
    }
    points.printPoints();

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
