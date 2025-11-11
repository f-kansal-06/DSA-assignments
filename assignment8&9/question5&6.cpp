#include<iostream>
using namespace std;

class heap{
    int arr[100];
    int size;

    public:
    heap(){
        arr[0] = -1;
        size = 0;
    }

   void insert(int val){   // insertion in a way of Max heap -> every childs value is less than its respective parents value 
        size = size + 1;
        int index = size;
        arr[size] = val;

        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
   }

   void print(){
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
   }

   void Delete(){
        if(size == 0){
            cout << "Nothing to Delete" << endl;
            return;
        }

        //step 1 : put value of last element to first
        arr[1] = arr[size];
        //step 2 : remove the last element from the array
        size--;

        int i = 1;
        while(i <= size){                // step 3 : bring the root element to correct position by comparing with its left and right child
            int leftChild = 2*i;         //left child of parent i is always at position 2*i for 1-index i.e. first element at arr[1]
            int rightChild = 2*i + 1;    //right child of parent i is always at position 2*i+1 for 1-index i.e. first element at arr[1]

            if(leftChild <= size && arr[i] < arr[leftChild]){
                swap(arr[i] , arr[leftChild]);
                i = leftChild;
            }
            else if(rightChild <= size && arr[i] < arr[rightChild]){
                swap(arr[i] , arr[rightChild]);
                i = rightChild;
            }
            else{
                return;
            }
        }
   }

};

void heapify(int arr[] , int n,int i){   //converting a random array to heap
    
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int b[], int n){
    int size = n;
    while(size > 1){
        swap(b[size] , b[1]);
        size--;

        heapify(b,size,1);
    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(70);
    h.print();

    int a[6] = {-1,54,53,65,52,60};
    int n = 5;
    for(int i=n/2 ; i>0 ; i--){
        heapify(a,n,i);
    }
    cout << "printing the heap => " << endl;
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    heapSort(a,n);
    cout << "printing the sorted heap => " << endl;
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}