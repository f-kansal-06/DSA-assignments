#include<iostream>
#include<stack>
using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main(){
    string s = "a+b*c+d*8*9+f";
    stack<char> st; 
    int i = 0;
    string answ;

    while(i < s.length()){
        char curr = s[i];
        if( (curr >=97 && curr<=122) || (curr >= '0' && curr <='9') ){
            answ += curr;
        }
        else{
            while( !st.empty() && prec(curr) <= prec(st.top()) ){
                answ += st.top();
                st.pop();
        }
        st.push(curr);
        }
         i++;
}
    while (!st.empty()) {
        answ += st.top();
        st.pop();
    }
    cout << answ << endl;
   return 0;
}