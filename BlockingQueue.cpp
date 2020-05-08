//
// Created by marcos on 8/5/20.
//

#include "BlockingQueue.h"

BlockingQueue::BlockingQueue() {
    finishedAdding = false;
}

void BlockingQueue::push(Resource* element) {
    std::unique_lock<std::mutex> lock(mtx);
    queue.push(element);
    cv.notify_all();
}

Resource* BlockingQueue::pop() {
    std::unique_lock<std::mutex> lock(mtx);
    if (!finishedAdding) {
        while (queue.empty()) {
            cv.wait(lock);
        }
        Resource* element = queue.front();
        queue.pop();
        return element;
    }
    return nullptr;
}

void BlockingQueue::doneAdding() {
    finishedAdding = true;
}

