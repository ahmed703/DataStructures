#include "Stack.h"

Stack::Stack(){
    top = -1;
    size = 0;
}

bool Stack::StackEmpty() const {
    return !size; // if size = 0, return 1 which is true
}

bool Stack::StackFull() const {
    return size == MAXSIZE ; // if size = MAXSIZE - 1, return 1 which is true
}

void Stack::push(){
    if (StackFull())
        cout << "\nStack is Full" << endl << endl;
    else {
        EntryType elementEntry;
        cout << "Inert an Element: ";
        cin >> elementEntry;
        top++;
        size++;
        entry[top] = elementEntry;
        cout << "\nElement pushed which is: " << entry[top] << endl << endl;
    }
}

void Stack::pop() {
    if (StackEmpty())
        cout << "\nStack is Empty." << endl << endl;
    else {
        cout << "\nElement popped which is: " << entry[top] << endl << endl;
        top--;
        size--;
    }
}

void Stack::getTop() {
    cout << "\nThe top Element is: " << entry[top] << endl << endl;
}

__attribute__((unused)) void Stack::StackSize() const {
    cout << "\nStack size is: " << size << endl << endl;
}

void Stack::printStack(){
    cout << "\nThe stack is(From the lower to the upper):\n[ ";
    for (int i = 0; i < top + 1; ++i) {
        cout << entry[i] << " ";
    }
    cout << "]\n" << endl;
}

void Stack::ClearStack() {
    top = -1;
    size = 0;
    cout << "Stack cleared successfully." << endl << endl;
}

void Stack::interface() {
    int Decision;
    do {
        cout << "This is a stack program.\nEnter a number from the following interface:"
                "\n1)Insert an Element.\t2)Delete an Element."
                "\t3)Peek the top Element.\t4)PrintStack."
                "\n5)Show the Stack size.\t6)Clear the whole Stack."
                "\n-1)Exit the program" << endl;
        cin >> Decision;
        switch (Decision) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                getTop();
                break;
            case 4:
                printStack();
                break;
            case 5:
                StackSize();
                break;
            case 6:
                ClearStack();
                break;
            case -1:
                cout << "Program exited successfully." << endl;
                exit(1);
            default:
                cout << "Enter a valid operation." << endl;
        }
    } while (Decision != -1);
}