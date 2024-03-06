class Solution {
public:
    bool isAnagram(string s, string t) {
        // TC: O(N), SC: O(N)
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;
        for (char ch : t) mp[ch]--;
        for (auto x : mp) {
            if (x.second != 0) return false;
        }
        return true;
    }
};
