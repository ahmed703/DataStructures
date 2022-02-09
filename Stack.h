#ifndef INC_1_STACKUSINGARRAYBASED_STACK_H
#define INC_1_STACKUSINGARRAYBASED_STACK_H

#include <iostream>
#define MAXSIZE 10

using namespace std;

using EntryType = int;

class Stack {

private:

    int top;
    int size;
    EntryType entry[MAXSIZE]{};

public:

    Stack();

    void push();

    void pop();

    void getTop();

    void printStack();

    void interface();

private:

    bool StackEmpty() const;

    bool StackFull() const;

    __attribute__((unused)) void StackSize() const;

    void ClearStack();
};

#endif //INC_1_STACKUSINGARRAYBASED_STACK_H