#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int row,col;
    int count = 0;

    cout << "enter number of row and col" << endl;
    cin >> row;
    cin >> col;
    int n = row * col;

    cout << "enter matrix elements" << endl;

        for(int i=0;i<n;i++){
            cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
               count++;
            }
        }
    }
    cout << "number of inversion : " << count << endl;
    return 0;
}