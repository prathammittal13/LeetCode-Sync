class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to store opening brackets
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);  // Push opening brackets to stack
            else {
                if (st.empty()) return false;  // No matching opening bracket
                char ch = st.top();
                st.pop();
                if ((s[i] == ')' && ch == '(') ||
                    (s[i] == ']' && ch == '[') ||
                    (s[i] == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty();
    }
};