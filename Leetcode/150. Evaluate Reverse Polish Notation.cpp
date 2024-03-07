class Solution {
    int calculate(int a, int b, string operand) {
        if (operand == "+") return a + b;
        else if (operand == "-") return a - b;
        else if (operand == "*") return a * b;
        else return a / b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        // TC: O(N), SC: O(N)
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(calculate(a, b, tokens[i]));
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
