#ifndef INC_2_QUEUEUSINIGLINKEDBASED_QUEUE_H
#define INC_2_QUEUEUSINIGLINKEDBASED_QUEUE_H

#include <iostream>

using namespace std;

using EntryType = int;

class Queue {

private:

    struct QueueNode {

        EntryType entry;

        QueueNode *next;
    };

    int size;

    QueueNode *rear;

    QueueNode *front;

public:

    Queue();

    void Enqueue();

    void Dequeue();

    void Peek();

    void printQueue();

    __attribute__((unused)) void ClearQueue();

    __attribute__((unused)) void QueueSize() const;

    void interface();

private:

    bool QueueEmpty() const;

    __attribute__((unused)) static bool QueueFull();
};

#endif //INC_2_QUEUEUSINIGLINKEDBASED_QUEUE_H