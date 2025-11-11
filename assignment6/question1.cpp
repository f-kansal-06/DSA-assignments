#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

// -------- Doubly Linked List --------
class DoublyLinkedList {
    Node *head;
public:
    DoublyLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertAtEnd(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found\n";
            return;
        }
        Node *n = new Node(val);
        n->next = temp->next;
        if (temp->next)
            temp->next->prev = n;
        temp->next = n;
        n->prev = temp;
    }

    void deleteNode(int key) {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int key) {
        Node *temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found!\n";
    }

    void display() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// -------- Circular Linked List --------
class CircularLinkedList {
    Node *last;
public:
    CircularLinkedList() { last = NULL; }

    void insertAtEnd(int val) {
        Node *n = new Node(val);
        if (last == NULL) {
            last = n;
            last->next = last;
            return;
        }
        n->next = last->next;
        last->next = n;
        last = n;
    }

    void insertAtBeginning(int val) {
        Node *n = new Node(val);
        if (last == NULL) {
            last = n;
            last->next = last;
            return;
        }
        n->next = last->next;
        last->next = n;
    }

    void deleteNode(int key) {
        if (!last)
            return;
        Node *curr = last->next, *prev = last;
        do {
            if (curr->data == key) {
                if (curr == last && curr->next == last) {
                    delete curr;
                    last = NULL;
                    return;
                }
                prev->next = curr->next;
                if (curr == last)
                    last = prev;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
        cout << "Node not found!\n";
    }

    void search(int key) {
        if (!last) return;
        Node *temp = last->next;
        do {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node not found!\n";
    }

    void display() {
        if (!last)
            return;
        Node *temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, val, key;
    cout << "1. Doubly Linked List\n2. Circular Linked List\nChoose: ";
    cin >> choice;

    if (choice == 1) {
        int ch;
        do {
            cout << "\n1.InsertBeg 2.InsertEnd 3.InsertAfter 4.Delete 5.Search 6.Display 7.Exit\n";
            cin >> ch;
            switch (ch) {
                case 1: cout << "Enter value: "; cin >> val; dll.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; dll.insertAtEnd(val); break;
                case 3: cout << "After which node: "; cin >> key; cout << "Value: "; cin >> val; dll.insertAfter(key,val); break;
                case 4: cout << "Delete value: "; cin >> key; dll.deleteNode(key); break;
                case 5: cout << "Search value: "; cin >> key; dll.search(key); break;
                case 6: dll.display(); break;
            }
        } while (ch != 7);
    }
    else if (choice == 2) {
        int ch;
        do {
            cout << "\n1.InsertBeg 2.InsertEnd 3.Delete 4.Search 5.Display 6.Exit\n";
            cin >> ch;
            switch (ch) {
                case 1: cout << "Enter value: "; cin >> val; cll.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; cll.insertAtEnd(val); break;
                case 3: cout << "Delete value: "; cin >> key; cll.deleteNode(key); break;
                case 4: cout << "Search value: "; cin >> key; cll.search(key); break;
                case 5: cll.display(); break;
            }
        } while (ch != 6);
    }
    return 0;
}
