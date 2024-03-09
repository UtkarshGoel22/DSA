class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // TC: O(N), SC: O(1)
        int left = 0, right = 0, n = s.length(), ans = 0;
        unordered_map<char, int> mp;
        while (right < n) {
            mp[s[right]]++;
            while (mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};
