#include "stack.h"

Stack::Stack() {
    size = 0;
    top = nullptr;
}

void Stack::push() {

    auto *p = new StackNode;
    EntryType elementEntry;
    cout << "Inert an Element: ";
    cin >> elementEntry;
    p->entry = elementEntry;
    cout << "\nElement pushed which is: " << p->entry << endl << endl;
    p->next = top;
    top = p;
    size++;
}

void Stack::pop() {
    if (StackEmpty()) {
        cout << "\nStack is Empty." << endl << endl;
    }
    else {
        StackNode *p;
        p = top;
        cout << "\nElement popped which is: " << p->entry << endl << endl;
        top = p->next;
        free(p);
        size--;
    }
}

void Stack::CheckSize() const {
    cout << "Stack size is: " << size << endl << endl;
}

bool Stack::StackEmpty() const {
    return size == 0;
}

__attribute__((unused)) bool Stack::StackFull() {
    return false;
}

void Stack::printStack() {
    if (StackEmpty())
        cout <<"\nStack is Empty" << endl << endl;
    else {
        StackNode *p;
        p = top;
        cout << "\nThe stack is(From the upper to the lower):\n[ ";
        while(p) {
            cout << p->entry << " ";
            p = p->next;
        }
        cout << "]" << endl << endl;
    }
}

void Stack::ClearStack() {
    if (StackEmpty())
        cout << "\nStack is already Empty" << endl << endl;
    else {
        StackNode *p, *q;
        p = q = top;
        while(p) {
            p = p->next;
            free(q);
            q = p;
        }
        size = 0;
        cout << "Stack Cleared Successfully." << endl << endl;
        top = nullptr;
    }
}

void Stack::Peek() {
    cout << "\nThe top element is: "<< top->entry << endl << endl;
}

void Stack::interface() {
    int Decision;
    do {
        cout << "This is a stack program.\nEnter a number from the following interface:"
                "\n1)Insert an Element.\t2)Delete an Element."
                "\t3)Peek the top Element.\t4)Print the Stack."
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
                Peek();
                break;
            case 4:
                printStack();
                break;
            case 5:
                CheckSize();
                break;
            case 6:
                ClearStack();
                break;
            case -1:
                cout << "Program exited successfully." << endl;
                cout << "Sin(q)/Cos(q) :)";
                exit(1);
            default:
                cout << "Enter a valid operation." << endl;
        }
    } while (Decision != -1);
}