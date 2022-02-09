#include "queue.h"

Queue::Queue() {
    size = 0;
    rear = front = nullptr;
}

void Queue::Enqueue() {
    auto *p = new QueueNode;
    EntryType elementEntry;
    cout << "Insert an Element: ";
    cin >> elementEntry;
    p->next = nullptr;
    p->entry = elementEntry;
    if  (!rear)
        front = p;
    else
        rear->next = p;
    rear = p;
    cout << "\nElement enqueued which is: " << elementEntry << endl << endl;
    size++;
}

void Queue::Dequeue() {

    if (QueueEmpty())
        cout << "\nQueue is Empty." << endl << endl;
    else {
        QueueNode *p;
        cout << "\nElement dequeued which is: " << front->entry << endl << endl;
        p = front;
        front = p->next;
        free(p);
        if (!front)
            rear = nullptr;
        size--;
    }
}

__attribute__((unused)) bool Queue::QueueFull() {
    return false;
}

bool Queue::QueueEmpty() const {
    return size == 0;
}

void Queue::Peek() {
    if (QueueEmpty())
        cout << "\nQueue is Empty" << endl << endl;
    else {
        cout << "\nThe First element is: " << front->entry << endl;
        cout << "\nThe Last element is: " << rear->entry << endl << endl;
    }
}

void Queue::QueueSize() const {
    cout << "\nThe Queue size is: " << size << endl << endl;
}

void Queue::printQueue() {
    QueueNode *p = front;
    cout << "\nThe Queue is(From the front element to the rear one):\n[ ";
    while(p) {
        cout << p->entry << " ";
        p = p->next;
    }
    cout << "]" << endl << endl;
}

void Queue::ClearQueue() {
    if (QueueEmpty())
        cout << "\nQueue is already Empty" << endl << endl;
    else {
        QueueNode *p = front, *q = front;
        while(p) {
            p = p->next;
            free(q);
            q = p;
        }
        size = 0;
        rear = front = nullptr;
        cout << "\nQueue Cleared Successfully." << endl << endl;
    }
}

void Queue::interface() {
    int Decision;
    do {
        cout << "This is a Queue program with no limited size."
                "\nEnter a number from the following interface:"
                "\n---------------------------------------------"
                "\n1)Insert an Element.\t2)Delete an Element."
                "\t3)Peek the rear and the front Elements.\t4)Print the Queue."
                "\n5)Clear the whole Queue.\t6)Show the Queue size."
                "\t-1)Exit the program" << endl;
        cin >> Decision;
        switch (Decision) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                printQueue();
                break;
            case 5:
                ClearQueue();
                break;
            case 6:
                QueueSize();
                break;
            case -1:
                cout << "Program exited successfully." << endl;
                exit(1);
            default:
                cout << "\nEnter a valid operation." << endl << endl;
        }
    } while (Decision != -1);
}