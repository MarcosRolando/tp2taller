#include "WorkerReader.h"
#include "ResourceReader.h"
#include "FileException.h"

#include "Inventory.h"
#include "Resource.h"
#include "BlockingQueue.h"
#include <vector>
#include <thread>
#include "Cook.h"
#include "Carpenter.h"
#include "Armourer.h"
#include "BenefitPoints.h"
#include "Farmer.h"
#include "Lumberjack.h"
#include "Miner.h"

int main() {
    Inventory inventory;
    BenefitPoints points;
    std::vector<BlockingQueue> resources(3);
    std::vector<Farmer*> farmer(4);
    std::vector<Lumberjack*> lumberjack(4);
    std::vector<Miner*> miner(4);
    std::vector<std::thread*> thread(21);
    std::vector<Cook*> cook(3);
    std::vector<Carpenter*> carpenter(3);
    std::vector<Armourer*> armourer(3);
    for (int i = 0; i < 3; ++i) {
        cook[i] = new Cook(inventory, points);
        carpenter[i] = new Carpenter(inventory, points);
        armourer[i] = new Armourer(inventory, points);
        thread[i] = new std::thread(&Cook::work, std::ref(cook[i]));
        thread[i+3] = new std::thread(&Carpenter::work, std::ref(carpenter[i]));
        thread[i+6] = new std::thread(&Armourer::work, std::ref(armourer[i]));
    }
    for (int i = 0; i < 4; ++i) {
        farmer[i] = new Farmer(inventory, resources[0]); //farmers
        thread[i+9] = new std::thread(&Farmer::work, std::ref(farmer[i]));
        lumberjack[i] = new Lumberjack(inventory, resources[1]); //lumberjacks
        thread[i+13] = new std::thread(&Lumberjack::work, std::ref(lumberjack[i]));
        miner[i] = new Miner(inventory, resources[2]); //miners
        thread[i+17] = new std::thread(&Miner::work, std::ref(miner[i]));
    }
    for (int i = 0; i < 3; ++i) {
        resources[0].push(Wheat);
    }
    for (int i = 0; i < 1; ++i) {
        resources[1].push(Wood);
    }
    for (int i = 0; i < 1; ++i) {
        resources[2].push(Coal);
    }
    for (int i = 0; i < 1; ++i) {
        resources[2].push(Iron);
    }
    resources[0].doneAdding();
    resources[1].doneAdding();
    resources[2].doneAdding();
    for (int i = 0; i < 21; ++i) {
        thread[i]->join();
    }
    for (int i = 0; i < 4; ++i) {
        delete farmer[i];
        delete lumberjack[i];
        delete miner [i];
    }
    for (int i = 0; i < 3; ++i) {
        delete cook[i];
        delete carpenter[i];
        delete armourer[i];
    }
    for (int i = 0; i < 21; ++i) {
        delete thread[i];
    }
    points.printPoints();
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
