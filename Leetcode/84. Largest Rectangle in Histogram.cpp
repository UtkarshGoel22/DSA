class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // TC: O(N), SC: O(N)
        int n = heights.size(), ans = 0;
        stack<int> st1, st2;
        vector<int> lb(n), rb(n);
        lb[0] = -1;
        st1.push(0);
        for (int i = 1; i < n; i++) {
            while (!st1.empty() && heights[st1.top()] >= heights[i]) st1.pop();
            if (st1.empty()) lb[i] = -1;
            else lb[i] = st1.top();
            st1.push(i);   
        }
        rb[n-1] = n;
        st2.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (!st2.empty() && heights[st2.top()] >= heights[i]) st2.pop();
            if (st2.empty()) rb[i] = n;
            else rb[i] = st2.top();
            st2.push(i);
        }
        for (int i = 0; i < n; i++) {
            int width = rb[i] - lb[i] - 1;
            int height = heights[i];
            int area = height * width;
            ans = max(ans, area);
        }
        return ans;
    }
};
