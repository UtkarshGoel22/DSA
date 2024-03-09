class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n), res;
        st.push(n-1);
        nge[n-1] = n;
        for (int i = n-2; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (st.empty()) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }
        int j = 0;
        for (int i = 0; i <= n-k; i++) {
            if (j < i) j = i;
            while (nge[j] < i+k) j = nge[j];
            res.push_back(nums[j]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            // remove out of bound element.
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            // remove the index of the elements which are smaller than the ith element from the deque.
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
