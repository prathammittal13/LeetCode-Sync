class Solution {
public:
        string removeOuterParentheses(string s) {
        string result = "";
        int level = 0;
        for (int i=0; i<s.length(); i++) {
           if(s[i] == ')') level--;
           if(level !=0) result.push_back(s[i]);
           if(s[i]== '(') level++;
        }
        return result;
    }
};