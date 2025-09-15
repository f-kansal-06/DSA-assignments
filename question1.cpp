#include<iostream>
using namespace std;

class queue{
    int *arr;
    int front;
    int rear;
    int size;
    public: 
    queue(int n){
        size = n;
        arr = new int[n];
        front = 0;
        rear = 0;
   }

   void enqueqe(int data){
    if(isFull() == 1){
        cout << "queue is full" << endl; 
        return;
    }
    arr[rear] = data;
    rear++;
   }
   void dequeqe(){
    if(isEmpty() == 1){
        cout << "queue is empty" << endl; 
        return;
    }
    //arr[front] = NULL;
    front++;
   }
    int isEmpty(){
        if(front == rear)
        return 1;
    }
    int isFull(){
        if(rear == size)
        return 1;
    }
    void peek(){
        cout << arr[front] << endl; 
    }
    void display(){
        for(int i = front; i<rear ;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
     ~queue() {
        delete[] arr; 
    }

};

int main(){
    queue q(5);
    q.enqueqe(1);
    q.peek();
    q.enqueqe(2);
    q.enqueqe(3);
    q.enqueqe(4);
    q.enqueqe(5);
    q.display();
    return 0;
}