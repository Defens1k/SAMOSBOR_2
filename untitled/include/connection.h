//
// Created by kekor on 01.04.19.
//

#ifndef UNTITLED_CONNECTION_H
#define UNTITLED_CONNECTION_H

#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "secure_queue.h"
#include "message.h"

#define MAX_LEN_INPUT_STR 8192
#define MULTICAST_ID 0

template <typename T>
class connection {
public:
    connection(int, int);
    connection() {;};
    bool empty();
    T get_message();
    void push(T);
    const bool operator < (const connection &);
    const bool operator > (const connection &);
    const bool operator == (const connection &);
    int id;

private:
    friend void * service(void * arg);
    secure_queue<T> in;
    secure_queue<T> out;
    int sock_fd;
    pthread_t thread;
    void * sending_out(void *);
};

#endif //UNTITLED_CONNECTION_H
