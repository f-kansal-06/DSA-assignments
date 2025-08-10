#include<iostream>
using namespace std;

int main(){
    int  arr[100];
    int arr2[100];
    int n,k=0;
    cout << "enter size of array " << endl;
    cin >> n;
    cout << "enter array" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int j=0; j<n; j++){
        for(int k=0; k < n - j - 1; k++){
            if(arr[k] > arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }

    k = 0;
    for(int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr2[k] = arr[i];
            k++;
        }
    }

    cout << "Distinct elements are: " <<endl;
    for(int i = 0; i < k; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}