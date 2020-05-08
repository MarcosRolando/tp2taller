//
// Created by marcos on 8/5/20.
//

#ifndef TP2TALLER_BLOCKINGQUEUE_H
#define TP2TALLER_BLOCKINGQUEUE_H

#include <mutex>
#include <condition_variable>
#include "Resource.h"
#include <queue>

class BlockingQueue {
private:
    std::queue<Resource*> queue;
    std::mutex mtx;
    std::condition_variable cv;
    bool finishedAdding;
public:
    BlockingQueue();
    void push(Resource* element);
    Resource* pop();
    void doneAdding();
};


#endif //TP2TALLER_BLOCKINGQUEUE_H
