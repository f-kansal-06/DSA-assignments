#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s = "(DAT(A(STRU)CTURE)S)";
    stack<char> st; 
    int i = 0;

    while(i < s.length()){
        char curr = s[i];

        if(curr == '('){
            st.push(curr);
        } 
        
        else if(curr == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
                
            } else {
                cout << "unbalanced brackets" << endl;
                return 0;
            }
        }

        i++;

    }

    if(st.empty()){
        cout << "balanced brackets" << endl;
    } else {
        cout << "unbalanced brackets" << endl;
    }

    return 0;
}
