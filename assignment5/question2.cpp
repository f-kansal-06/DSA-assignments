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

    int countAndDeleteKey(int key){
        int count = 0;
        Node* temp = head;
        Node* prev = nullptr;

        while (temp) {
            if (temp->data == key) {
                count++;
                if (temp == head) {
                    head = temp->next;
                    delete temp;
                    temp = head;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return count;
    }

    void display(){
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(3);
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);

    cout << "Original list: ";
    list.display();

    int key = 1;
    int count = list.countAndDeleteKey(key);

    cout << "Count: " << count << endl;
    cout << "Updated list: ";
    list.display();
}