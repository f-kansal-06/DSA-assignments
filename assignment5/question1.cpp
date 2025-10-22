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
    LinkedList() { head = NULL; }

    // Insertion
    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    void insertBeforeValue(int value, int val){
        if (!head) return;
        if (head->data == value) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;
        if (!temp->next) {
            cout << "Value not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertAfterValue(int value, int val){
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (!temp) {
            cout << "Value not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Deletion
    void deleteFromBeginning(){
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteFromEnd(){
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecificNode(int value){
        if (!head) return;
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;
        if (!temp->next) {
            cout << "Node not found!\n";
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // Search and Display
    void search(int value){
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Node found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }
    void display(){
        Node* temp = head;
        if (!temp) {
            cout << "List is empty!\n";
            return;
        }
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, value;

    while (true) {
        cout << "\n===== Singly Linked List Menu =====\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before a value\n";
        cout << "4. Insert after a value\n5. Delete from beginning\n6. Delete from end\n";
        cout << "7. Delete a specific node\n8. Search for a node\n9. Display\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter value: "; 
                cin >> val; 
                list.insertAtBeginning(val); 
                break;
            case 2: 
                cout << "Enter value: "; 
                cin >> val; 
                list.insertAtEnd(val);
                break;
            case 3: 
                cout << "Insert before which value? "; 
                cin >> value; 
                cout << "Enter value: "; 
                cin >> val; 
                list.insertBeforeValue(value, val); 
                break;
            case 4: 
                cout << "Insert after which value? "; 
                cin >> value; cout << "Enter value: "; 
                cin >> val; 
                list.insertAfterValue(value, val);
                break;
            case 5: 
                list.deleteFromBeginning(); 
                break;
            case 6: 
                list.deleteFromEnd(); 
                break;
            case 7: 
                cout << "Enter value to delete: "; 
                cin >> value;
                list.deleteSpecificNode(value);
                break;
            case 8: 
                cout << "Enter value to search: "; 
                cin >> value;
                list.search(value);
                break;
            case 9: 
                list.display();
                 break;
            case 10: exit(0);

            default: cout << "Invalid choice!\n";
        }
    }
}
