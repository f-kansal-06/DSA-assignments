#include <iostream>
using namespace std;

struct DNode {
    char data;
    DNode *next, *prev;
    DNode(char v) : data(v), next(nullptr), prev(nullptr) {}
};

bool isPalindrome(DNode *head) {
    if (!head) return true;
    DNode *left = head;
    DNode *right = head;
    // go to tail
    while (right->next) right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    // Example: L → E → V → E → L
    DNode *head = new DNode('L');
    head->next = new DNode('E');
    head->next->prev = head;
    head->next->next = new DNode('V');
    head->next->next->prev = head->next;
    head->next->next->next = new DNode('E');
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DNode('L');
    head->next->next->next->next->prev = head->next->next->next;

    cout << "List is palindrome? " << (isPalindrome(head) ? "True" : "False") << "\n";

    // Cleanup
    auto p = head->next->next->next->next;
    delete p;
    p = head->next->next->next;
    delete p;
    p = head->next->next;
    delete p;
    p = head->next;
    delete p;
    delete head;

    return 0;
}
