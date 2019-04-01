//
// Created by kekor on 01.04.19.
//

#ifndef UNTITLED_SECURE_QUEUE_H
#define UNTITLED_SECURE_QUEUE_H

#include <queue>
#include <mutex>

template <typename T>
class secure_queue {
public:
    bool empty();
    void pop();
    const T& front();
    void push(const T&);
    void lock();
    void unlock();
private:
    std::recursive_mutex mut;
    std::queue<T> que;
};

void fooooooooooooooooooooooooooooooooooo();

#endif //UNTITLED_SECURE_QUEUE_H
