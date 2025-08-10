#include<iostream>
using namespace std;

int main (){
    int arr[100];
    int n;
    int flag;
    cout << "enter size of array " << endl;
    cin >> n;
    cout << "enter array in sorted order" << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int target;
        cout << "enter target element" << endl;
        cin >> target;

    cout << endl << endl;

    int s = 0;
    int e = n-1;
    int m = s+(e-s)/2;

    while(s<=e){
    if(arr[m] == target){
        flag = 1;
    }
    if(arr[m] > target){
        s = m+1;
    }
    else{
        e = m-1;
    }
    m = s+(e-s)/2;
}
if(flag == 1){
    cout<< "element found" << endl;
}
else{
    cout<< "element not found" << endl;
}
return 0;
}