#include "list.h"

List::List() {
    size = 0;
    head = nullptr;
}

void List::Insert() {
    auto *p = new ListNode;
    EntryType elementEntry;
    int position;
    cout << "Inert an Element:";
    cin >> elementEntry;
    cout << "Select the position you wish to insert into:";
    cin >> position;
    if (position <= size) {
        cout << "\nElement inserted which is: " << elementEntry << endl << endl;
        if (ListEmpty())
            head = p;
        else {
            int count = 1;
            ListNode *q = head;
            while(count < position) {
                q = q->next;
                count++;
            }
            if (size == position) {
                q->next = p;
                p->next = nullptr;
            }
            else {
                ListNode *l = q->next;
                q->next = p;
                p->next = l;
                q->entry = elementEntry;
            }
        }
        size++;
    }
    else
        cout <<"\nError:You must insert in the range of [0, size + 1].\nReturning to the main interface ......." << endl << endl;
}

void List::Delete() {
    if (ListEmpty())
        cout << "\nList is Empty." << endl << endl;
    else {
        int position;
        cout << "Select the position you wish to delete from:";
        cin >> position;
        if (position < size) {
            ListNode *p = head;
            while (p) {
                int count = 1;
                while (count < position) {
                    p = p->next;
                    count++;
                }
                ListNode *q = p->next;
                if  (q->next) {
                    ListNode *l = q->next;
                    p->next = l;
                }
                else
                    q->next = nullptr;
                free(q);
                cout << "\nElement deleted which is: " << q->entry << endl << endl;
                size--;
            }
        }
        else
            cout << "\nError:You must delete in the range of [0, size[.\nReturning to the main interface ......."<< endl << endl;
    }
}

void List::printList() {
    if (ListEmpty())
        cout << "\nList is Empty." << endl << endl;
    else {
        ListNode *p = head;
        while(p) {
            cout << p->entry << " ";
            p = p->next;
        }
    }
}

void List::ClearList() {
    if (ListEmpty())
        cout <<"List is already Empty." << endl << endl;
    else {
        ListNode *p = head, *q  = head;
        while (p) {
            p = p->next;
            free(q);
            q = p;
        }
        size = 0;
        head = nullptr;
    }
}

bool List::ListEmpty() const {
    return size == 0;
}

__attribute__((unused)) bool List::ListFull() {
    return false;
}

void List::CheckSize() const {
    cout << "\nList size is: " << size << endl << endl;
}

void List::interface() {
    int Decision;
    do {
        cout << "This is a list program with no size limit."
                "\nEnter a number from the following interface:"
                "\n--------------------------------------------"
                "\n1)Insert an Element.\t2)Delete an Element."
                "\t3)Show the List size.\t4)Print the List."
                "\n5)Clear the whole List."
                "\t-1)Exit the program" << endl;
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