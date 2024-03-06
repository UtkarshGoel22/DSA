class Solution {
public:
    bool isValid(string s) {
        // TC: O(N), SC: O(N);
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if (st.size()) {
                    char open = st.top();
                    if ((ch == ')' && open != '(') || (ch == '}' && open != '{') || (ch == ']' && open != '[')) return false;
                    st.pop();
                }
                else return false;
            }
        }
        return st.size() > 0 ? false : true;
    }
};
