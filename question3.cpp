#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    queue<int> q1;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    int n = q.size();
    
    for(int i=0;i<n/2;i++){
        int val = q.front();
        q.pop();
        q1.push(val);
    }
    while(!q1.empty()){
        int val = q1.front();
        q1.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }
    while(!q.empty()){
        int val = q.front();
        q.pop();
        cout << val << " ";
    }
    cout << endl;
    return 0;
}