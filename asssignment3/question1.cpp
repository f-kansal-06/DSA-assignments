#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int size;

public:
    Stack(int n) {
        arr = new int[n];
        size = n;
        top = -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
        } else {
             arr[top] = -1;
            top--;
        }
    }

    bool isFull() {
        return (top == size - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
        } else {
            cout << arr[top] << endl;
        }
    }

    ~Stack() {
        delete[] arr; 
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    s.peek();  

    s.pop();
    s.peek(); 

    s.pop();
    s.pop();
    s.pop();

    return 0;
}
