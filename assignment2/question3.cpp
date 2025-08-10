#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int n,answ;
    cout << "enter size of array " << endl;
    cin >> n;
    cout << "enter array" << endl;
    for(int i=0; i<n-1; i++){
        cin >> arr[i];
    }
    for(int i=0 ; i<n;i++){
        if(arr[i]-i != 1){
            answ = i+1;
            break;
        }
    }
    cout << "missing element is : " << answ << endl;
    return 0;
}