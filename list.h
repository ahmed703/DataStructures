#ifndef INC_3_LISTUSINGLINKEDBASED_LIST_H
#define INC_3_LISTUSINGLINKEDBASED_LIST_H

#include <iostream>
#include <cstring>

using namespace std;

using EntryType = int;

class List {

private:

    struct ListNode {

        EntryType entry;

        ListNode *next;

    };

    int size;

    ListNode *head{};

public:

    List();

    void Insert();

    void Delete();

    void CheckSize() const;

    void printList();

    void ClearList();

    void interface();

private:

    bool ListEmpty() const;

    __attribute__((unused)) static bool ListFull();
};

#endif //INC_3_LISTUSINGLINKEDBASED_LIST_H