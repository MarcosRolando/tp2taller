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
    while (queue.empty() && !finishedAdding) {
        cv.wait(lock);
    }
    if (!queue.empty()) {
        Resource* element = queue.front();
        queue.pop();
        return element;
    }
    return nullptr;
}

bool BlockingQueue::empty() {
    return (finishedAdding && queue.empty());
}

void BlockingQueue::doneAdding() {
    std::unique_lock<std::mutex> lock(mtx);
    finishedAdding = true;
    cv.notify_all();
}

