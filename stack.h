#ifndef INC_1_STACKUSINGLINKEDBASED_STACK_H
#define INC_1_STACKUSINGLINKEDBASED_STACK_H

#include <iostream>

using namespace std;
using EntryType = int;

class Stack {

private:

    struct StackNode {

        EntryType entry;

        StackNode *next;
    };

    int size;

    StackNode *top;

public:

    Stack();

    void push();

    void pop();

    void CheckSize() const;

    bool StackEmpty() const;

    __attribute__((unused)) static bool StackFull();

    void printStack();

    void ClearStack();

    void Peek();

    void interface();
};

#endif //INC_1_STACKUSINGLINKEDBASED_STACK_H