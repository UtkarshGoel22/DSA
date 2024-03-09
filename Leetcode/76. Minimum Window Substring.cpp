class Solution {
public:
    string minWindow(string s, string t) {
        // TC: O(N), SC: O(1)
        int n = s.length(), m = t.length();
        if (s.empty() || t.empty() || n < m) return "";
        vector<int> freq(128);
        int count = m;
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        for (char ch : t) freq[ch]++;
        while (end < n) {
            if (freq[s[end]] > 0) count--;
            freq[s[end]]--;
            end++;
            while (count == 0) {
                if (end - start < minLen) {
                    minLen = end - start;
                    startIndex = start;
                }
                // Frequency of all those characters will be zero before increment
                // which are present in string t. Because characters present only
                // in string s willl be negative before the increment.
                if (freq[s[start]] == 0) count++;
                freq[s[start]]++;
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
