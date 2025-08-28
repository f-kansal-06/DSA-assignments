#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s = "DATASTRUCTURES";
    stack<int> st;
    int i = 0;
    while(i<s.length()){
        st.push(s[i]);
        i++;
    }
    while(!st.empty()){
        char val = st.top();
        st.pop();
        cout << val;
    }
    cout << endl;

    return 0;
}