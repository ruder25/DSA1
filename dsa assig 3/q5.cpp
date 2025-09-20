#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> st;
    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch (c) {
            case '+': st.push(val1 + val2); break;
            case '-': st.push(val1 - val2); break;
            case '*': st.push(val1 * val2); break;
            case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix = "231*+9-"; // Equivalent to (2 + (3*1)) - 9
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation: " << evaluatePostfix(postfix) << endl;
    return 0;
}