class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), left = 0, right = 0, ans = 0;
        while (right < n) {
            if (prices[left] < prices[right]) {
                ans = max(ans, prices[right] - prices[left]);
            }
            else {
                left = right;
            }
            right++;
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0, mini = prices[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};
