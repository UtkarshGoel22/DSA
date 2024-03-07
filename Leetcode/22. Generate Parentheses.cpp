// -----------------BRUTE-------------------
class Solution {
public:
    bool check(string s) {
        int n = s.length();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(s[i]);
            else {
                if (st.size()) {
                    if (st.top() == ')') return false;
                    else st.pop();
                }
                else return false;
            }
        }
        return st.size() == 0 ? true : false;
    }
    void solve(vector<string>& res, string s, int open, int close) {
        if (open == 0 && close == 0) {
            if (check(s)) res.push_back(s);
        }
        else {
            if (open) solve(res, s+'(', open-1, close);
            if (close) solve(res, s+')', open, close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> res;
        solve(res, s, n, n);
        return res;
    }
};


// -----------------BETTER-------------------
class Solution {
public:
    void solve(vector<string>& res, string s, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        if (open > 0) {
            solve(res, s+'(', open-1, close);
        }
        if (close > open) {
            solve(res, s+')', open, close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res, "", n, n);
        return res;
    }
};
