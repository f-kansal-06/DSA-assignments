#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){ 
        this->data = data;
        this->next = NULL;
    }

    void print(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reversal(Node* &head){
        Node* curr = head;
        Node* prev = NULL;
        Node* forw = NULL;

        while(curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        head = prev; 
    }

    Node* kReversal(Node* head, int k){
        if(head == NULL) return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* forw = NULL;
        int count = 0;

        while(curr != NULL && count < k){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;
        }

        // recursively reverse remaining list
        if(forw != NULL){
            head->next = kReversal(forw, k);
        }

        return prev;
    }
};

int main(){
    Node* head = new Node(12);
    head->next = new Node(20);
    head->next->next = new Node(8);
    head->next->next->next = new Node(43);
    head->next->next->next->next = new Node(19);
    head->next->next->next->next->next = new Node(28);

    head->print(head);

    head->reversal(head);
    head->print(head);

    head = head->kReversal(head, 2);
    head->print(head);

    return 0;
}