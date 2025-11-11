#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *next, *prev;
    DNode(int v) : data(v), next(nullptr), prev(nullptr) {}
};

// size of doubly linked list
int sizeDoubly(DNode *head) {
    int count = 0;
    DNode *p = head;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

// For circular singly linked list
struct CNode {
    int data;
    CNode *next;
    CNode(int v) : data(v), next(nullptr) {}
};

int sizeCircular(CNode *head) {
    if (!head) return 0;
    int count = 0;
    CNode *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    // (i) Doubly linked list: e.g. 10 <-> 20 <-> 30 <-> 40
    DNode *dhead = new DNode(10);
    dhead->next = new DNode(20);
    dhead->next->prev = dhead;
    dhead->next->next = new DNode(30);
    dhead->next->next->prev = dhead->next;
    dhead->next->next->next = new DNode(40);
    dhead->next->next->next->prev = dhead->next->next;

    cout << "Size of doubly linked list: " << sizeDoubly(dhead) << "\n";

    // (ii) Circular linked list: e.g. 5 → 15 → 25 → (back to 5)
    CNode *chead = new CNode(5);
    chead->next = new CNode(15);
    chead->next->next = new CNode(25);
    chead->next->next->next = chead;

    cout << "Size of circular linked list: " << sizeCircular(chead) << "\n";

    // (Cleanup omitted for clarity)
    return 0;
}
