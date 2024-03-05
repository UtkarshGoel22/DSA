class Solution {
public:
    // Using Ordered Map
    int longestConsecutive(vector<int>& nums) {
        // TC: O(N), SC: O(N)
        int cnt = 1, ans = 1, n = nums.size();
        if (n == 0) return 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = 1;
        }
        auto prev = mp.begin();
        auto it = mp.begin();
        ++it;
        for (; it != mp.end(); ++prev, ++it) {
            if ((prev)->first + 1 == it->first) {
                cnt++;
                ans = max(ans, cnt);
            }
            else {
                cnt = 1;
            }
        }
        return ans;
    }

    // Using Unordered Set
    int longestConsecutive(vector<int>& nums) {
        // TC: O(N), SC: O(N)
        unordered_set<int> s;
        for (int x : nums) s.insert(x);
        int ans = 0;
        for (int x : nums) {
            if (s.find(x-1) == s.end()) {
                int currentNum = x;
                int currentStreak = 1;
                while (s.find(currentNum+1) != s.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                ans = max(ans, currentStreak);
            }
        }
        return ans;
    }
};
