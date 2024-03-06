class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        // TC: O(N), SC: O(N)
        unordered_map<int, int> mp;
        for (int num : nums) {
            if (mp.find(num) != mp.end()) return true;
            mp[num] = 1;
        }
        return false;
    }
};
