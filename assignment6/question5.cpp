#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int v) : data(v), next(nullptr) {}
};

bool isCircular(Node *head) {
    if (!head) return false;
    Node *temp = head->next;
    while (temp && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

int main() {
    // Example list: 2 → 4 → 6 → 7 → 5 → (back to 2)  => circular
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;  // make circular

    cout << "Linked list is circular? " << (isCircular(head) ? "True" : "False") << "\n";

    // If you want also test a non-circular version:
    Node *head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    // no linking back

    cout << "Second linked list is circular? " << (isCircular(head2) ? "True" : "False") << "\n";

    // Cleanup (not fully correct for circular one but for demo)
    head->next->next->next->next->next = nullptr;
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    delete head2->next->next;
    delete head2->next;
    delete head2;

    return 0;
}
