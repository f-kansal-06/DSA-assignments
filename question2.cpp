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
        front = -1;
        rear = -1;
   }

   void enqueqe(int data){
    if(isFull() == 1){
        cout << "queue is full" << endl; 
        return;
    }
    if(front == -1){  // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    arr[rear] = data;
   }

   void dequeqe(){
    if(isEmpty() == 1){
        cout << "queue is empty" << endl; 
        return;
    }
     if(front == rear){ // single element
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
   }

    int isEmpty(){
        if(front == -1)
        return 1;
        else return 0;
    }

    int isFull(){
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1)) )
        return 1;
        else return 0;
    }

    void peek(){
        cout << arr[front] << endl; 
    }

    void display(){
       if(isEmpty() == 1){
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while(true){
            cout << arr[i] << " ";
            if(i == rear) break;
            i = (i + 1) % size;
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
    q.enqueqe(5);
    q.display();
    q.dequeqe();
    q.enqueqe(7);
    q.display();
    return 0;
}