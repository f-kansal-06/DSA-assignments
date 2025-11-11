#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int v) : data(v), next(nullptr) {}
};

void displayCircular(Node *head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    // first pass until we come back to head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    // repeat head’s data at end as per the requirement
    cout << head->data;
    cout << "\n";
}

int main() {
    // Create circular list: 20 → 100 → 40 → 80 → 60 → (back to 20)
    Node *head = new Node(20);
    head->next = new Node(100);
    head->next->next = new Node(40);
    head->next->next->next = new Node(80);
    head->next->next->next->next = new Node(60);
    head->next->next->next->next->next = head;  // make circular

    cout << "Circular list contents (with head repeated): ";
    displayCircular(head);

    // Free memory (optional for this demo)
    Node *temp = head->next->next->next->next;
    temp->next = nullptr;  // break circle
    Node *p = head;
    while (p) {
        Node *q = p->next;
        delete p;
        p = q;
    }

    return 0;
}
