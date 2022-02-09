#ifndef INC_3_LISTUSINGARRAYBASED_LIST_H
#define INC_3_LISTUSINGARRAYBASED_LIST_H

#include <bits/stdc++.h>
#define MAXSIZE 10

using namespace std;
using EntryType = int;

class List {
    EntryType entry[MAXSIZE]{};
    int size;

public:

    List();

    bool ListEmpty() const;

    bool ListFull() const;

    void Insert();

    void Delete();

    void printList();

    void CheckSize() const;

    void ClearList();

    void interface();
};

#endif //INC_3_LISTUSINGARRAYBASED_LIST_H