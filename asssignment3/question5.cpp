#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    stack<int> st;
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};

    for (int i = 0; i < arr.size(); i++) {
        string curr = arr[i];

        if(curr >= "0" && curr <= "9") {
            st.push(stoi(curr));     // stoi -> conversion of string to integer
        }
        else {
            int val1 = st.top(); 
            st.pop();
            int val2 = st.top(); 
            st.pop();
            
            if (curr == "+")
                st.push(val2 + val1);
            else if (curr == "-")
                st.push(val2 - val1);
            else if (curr == "*")
                st.push(val2 * val1);
            else if (curr == "/")
                st.push(val2 / val1);
        }
    }
    cout << "answer is : " << st.top();
    return 0;
}
