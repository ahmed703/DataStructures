#include "Queue.h"

Queue::Queue() {
    size = 0;
    front = -1;
    rear = 0;
}

void Queue::Enqueue() {
    if (!QueueFull()) {
        if (front == MAXSIZE - 1)
            front = -1;
        front++;
        size++;
        EntryType elementEntry;
        cout << "Insert an Element: ";
        cin >> elementEntry;
        entry[front] = elementEntry;
        cout << "\nElement enqueued which is: " << entry[front] << endl << endl;
        }
    else
        cout << "\nQueue is Full." << endl << endl;
}

void Queue::Dequeue() {
    if (QueueEmpty()) {
        if (rear == MAXSIZE - 1)
            rear = -1;
        cout << "\nElement dequeued which is: " << entry[rear] << endl << endl;
        rear++;
        size--;
    }
    else
        cout << "\nQueue is Empty." << endl << endl;
}

bool Queue::QueueEmpty() const {
    return size;
}

bool Queue::QueueFull() const {
    return size == MAXSIZE;
}

void Queue::printQueue() {
    cout << "\nThe Queue is(From the front element to the rear one):\n-------------------------------->\n[ ";
    for (int i = rear; i <= front; ++i) {
        if (rear == MAXSIZE - 1)
            i = 0;
        cout << entry[i] << " ";
    }
    cout << "]" << endl << endl;
}

void Queue::Peek() const {
    if (!QueueEmpty())
        cout << "\nQueue is Empty" << endl << endl;
    else {
        cout << "\nThe First element is: " << entry[rear] << endl;
        cout << "\nThe Last element is: " << entry[front] << endl << endl;
    }
}

__attribute__((unused)) void Queue::ClearQueue() {
    size = 0;
    front = -1;
    rear = 0;
    entry[rear] = 0;
    cout << "Queue cleared successfully." << endl;
}

__attribute__((unused)) void Queue::QueueSize() const {
    cout << "\nThe Queue size is: " << size << endl << endl;
}

void Queue::interface() {
    int Decision;
    do {
        cout << "This is a Queue program with a limited size of 10."
                "\nEnter a number from the following interface:"
                "\n--------------------------------------------------"
                "\n1)Insert an Element.\t2)Delete an Element."
                "\t3)Peek the front and the rear Elements.\t4)Print the Queue."
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