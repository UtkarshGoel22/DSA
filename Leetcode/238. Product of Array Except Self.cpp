class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TC: O(N), SC: O(1)
        int n = nums.size();
        vector<int> ans(n, 1);
        int left_product = 1, right_product = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= left_product;
            left_product *= nums[i];
        }
        for (int i = n-1; i >= 0; i--) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }
        return ans;
    }
};
