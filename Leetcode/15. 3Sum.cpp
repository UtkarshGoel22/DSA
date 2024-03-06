class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // TC: O(NlogN + N*N), SC: O(1)
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] > 0) break;
            if (nums[i] + nums[n-2] + nums[n-1] < 0) continue;
            int j = i+1, k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    do {j++;} while (nums[j] == nums[j-1] && j < k);
                    do {k--;} while (nums[k] == nums[k+1] && j < k);
                }
            }
        }
        return res;
    }
};
