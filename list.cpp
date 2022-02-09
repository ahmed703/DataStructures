#include "list.h"

List::List() {
    size = 0;
}

void List::Insert() {
    if (ListFull()) {
        cout << "List is full." << endl;
    }
    else {
        EntryType elementEntry;
        int position;
        cout << "Inert an Element:";
        cin >> elementEntry;
        cout << "Select the position you wish to insert into:";
        cin >> position;
        if (position <= size) {
            cout << "\nElement inserted which is: " << entry[position] << endl << endl;
            for (int i = size; i >= position; --i) {
                entry[i + 1] = entry[i];
            }
            entry[position] = elementEntry;
            size++;
        }
        else
            cout <<"\nError:You must insert in the range of [0, size + 1].\nReturning to the main interface ......." << endl << endl;
    }
}

void List::Delete() {
    if (ListEmpty())
        cout << "\nList is Empty." << endl << endl;
    else {
        int position;
        cout << "Select the position you wish to delete from:";
        cin >> position;
        if (position < size) {
            cout << "\nElement deleted which is: " << entry[position] << endl << endl;
            for (int i = position + 1; i < size; ++i) {
                entry[i - 1] = entry[i];
            }
            size--;
        }
        else
            cout <<"\nError:You must delete in the range of [0, size[.\nReturning to the main interface ......." << endl << endl;
    }
}

void List::printList() {
    cout << "\nThe list is(From the first to the last):\n[ ";
    for (int i = 0; i < size; ++i) {
        cout << entry[i] << " ";
    }
    cout << "]" << endl << endl;
}

void List::ClearList() {
    size = 0;
    cout << "List Cleared successfully." << endl << endl;
}

bool List::ListEmpty() const {
    return size == 0;
}

bool List::ListFull() const {
    return size == MAXSIZE;
}

void List::CheckSize() const {
    cout << "\nList size is: " << size << endl << endl;
}

void List::interface() {
    int Decision;
    do {
        cout << "This is a list program with a size limit of 10."
                "\nEnter a number from the following interface:"
                "\n--------------------------------------------"
                "\n1)Insert an Element.\t2)Delete an Element."
                "\n3)Show the List size.\t4)Print the List."
                "\n5)Clear the whole List."
                "\n-1)Exit the program" << endl;
        cin >> Decision;
        switch (Decision) {
            case 1:
                Insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                CheckSize();
                break;
            case 4:
                printList();
                break;
            case 5:
                ClearList();
                break;
            case -1:
                cout << "Program exited successfully." << endl;
                exit(1);
            default:
                cout << "Enter a valid operation." << endl;
        }
    } while (Decision != -1);
}