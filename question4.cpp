#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    string test = "aabc";
    unordered_map<char,int> count;
    queue<char> q;
    string answ = "";

    for (int i=0;i<test.size();i++){
        char curr = test[i];
        count[curr]++;
        q.push(curr);

        while(!q.empty()){
            if(count[q.front()]>1){
                q.pop();
            }
            else{
                answ.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            answ += "-1"; 
        }
    }
    cout << answ << endl;
    return 0;
}