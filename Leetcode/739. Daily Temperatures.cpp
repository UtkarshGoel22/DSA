class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // TC: O(N), SC: O(N)
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int, int>> st;
        st.push({n-1, temperatures[n-1]});
        for (int i = n-2; i >= 0; i--) {
            while (!st.empty() && st.top().second <= temperatures[i]) st.pop();
            if (st.empty()) res[i] = 0;
            else res[i] = st.top().first - i;
            st.push({i, temperatures[i]});
        }
        return res;
    }
};
