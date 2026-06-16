class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to store opening brackets
        for (auto it : s) {
            if (it == '(' || it == '{' || it == '[')
                st.push(it);  // Push opening brackets to stack
            else {
                if (st.empty()) return false;  // No matching opening bracket
                char ch = st.top();
                st.pop();
                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty();
    }
};