#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { 
        data = val; 
        next = NULL; 
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() { 
        head = NULL; 
    }

    void insert(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void findMiddle(){
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    cout << "Linked list: 1->2->3->4->5\n";
    list.findMiddle();
}
