class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // TC: O(N*MlogM), SC: O(N) where N is number of strings and M is max length of string.
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (mp.find(tmp) != mp.end()) {
                res[mp[tmp]].push_back(strs[i]);
            }
            else {
                mp[tmp] = res.size();
                res.push_back({strs[i]});
            }
        }
        return res;
    }
};
