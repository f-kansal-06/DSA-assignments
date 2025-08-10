#include<iostream>
using namespace std;

int main(){
    int arr1[3][3] = {1,2,3,4,5,6,7,8,9};
    int flag = 0;

    //PART A
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(i == j){
    //             cout << arr1[i][j] << " ";
    //         }
    //     }
    // }
    // cout << endl;

    //PART C  UPPER TRI
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(j>=i){
    //             cout << arr1[i][j] << " ";
    //         }
    //     }
    // }
    // cout << endl;

    //PART D  LOWER TRI
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(j<=i){
    //             cout << arr1[i][j] << " ";
    //         }
    //     }
    // }
    // cout << endl;

    //PART E SYMMETRIC MATRIX
    // int arr2[3][3] = {1,1,1,1,1,1,1,1,1};
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(arr2[i][j] == arr2[j][i]){    // can use arr1 also
    //             flag = 1;
    //         }
    //         else{
    //             flag = 0;
    //             break;
    //         }
    //     }
    // }
    // if(flag == 1){
    //     cout << "its a symmetric matrix" << endl;
    // }
    // else{
    //     cout << "its not a symmetric matrix" << endl;
    // }
    return 0;
}