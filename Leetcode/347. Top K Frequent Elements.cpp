class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // TC: O(N+N+(N*K)), SC: O(N)
        int n = nums.size();
        unordered_map<int, int> freqency; // element, frequency
        map<int, vector<int>> buckets; // frequency, [elements]
        vector<int> res;
        for (int num : nums) freqency[num]++;
        for (auto x : freqency) buckets[x.second].push_back(x.first);
        for (auto it = buckets.rbegin(); it != buckets.rend() && k > 0; it++) {
            for (int j = 0; j < it->second.size() && k > 0; j++, k--) {
                res.push_back(it->second[j]);
            }
        }
        return res;
    }
};
