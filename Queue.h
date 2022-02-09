#ifndef INC_2_QUEUEUSINGARRAYBASED_QUEUE_H
#define INC_2_QUEUEUSINGARRAYBASED_QUEUE_H

#include <iostream>
#define MAXSIZE 10
using namespace std;

using EntryType = int;

class Queue {
    EntryType entry[MAXSIZE]{};
    int front;
    int rear;
    int size;

public:
    Queue();

    void Enqueue();

    void Dequeue();

    void printQueue();

    void Peek() const;

    void interface();

    __attribute__((unused)) void ClearQueue();

    __attribute__((unused)) void QueueSize() const;

private:

    bool QueueEmpty() const;

    bool QueueFull() const;
};

#endif //INC_2_QUEUEUSINGARRAYBASED_QUEUE_H
