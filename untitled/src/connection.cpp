#include "connection.h"

template <typename T>
void * service(connection<T>* arg) {        //  сюда NULL прелитит ????????????????????
    connection<message> * con = static_cast<connection<message> *>(arg);
    char buff[MAX_LEN_INPUT_STR];
    int lenght = 0;
    while(1) {
        while (con->out.empty() == false) {
            send(con->sock_fd, "message", strlen("message"), 0);
        }

        while (lenght = recv(con->sock_fd, buff, MAX_LEN_INPUT_STR, 0) > 0) {
            if (lenght < 0) {
                std::cerr << "error input on socket " << con->sock_fd << " on client with id " << con->id << std::endl;
            }
            buff[lenght] = '\0';
            con->in.push(message(con->id, strlen(buff)));
        }
    }
}

template <typename T>
connection<T>::connection(int sock, int in_id) {
    sock_fd = sock;
    id = in_id;
    pthread_create(&thread, NULL, service<T>, NULL);        //Почему не this ??????????????????
}

template <typename T>
bool connection<T>::empty() {
    return in.empty();
}

template <typename T>
T connection<T>::get_message() {
    message result = in.front();
    in.pop();
    return result;
}

template <typename T>
void connection<T>::push(T msg) {
    out.push(msg);
}

const bool operator < (const connection<message> & a, const connection<message> & b) {
    return a.id < b.id;
}

const bool operator > (const connection<message> & a, const connection<message> & b) {
    return a.id > b.id;
}

const bool operator == (const connection<message> & a, const connection<message> & b) {
    return a.id == b.id;
}
