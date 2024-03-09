class Solution {
public:
    int characterReplacement(string s, int k) {
        // TC: O(N), SC: O(1)
        vector<int> freq(26);
        int n = s.length(), ans = 0, maxi = 0;
        for (int i = 0, j = 0; i < n; i++) {
            freq[s[i]-'A']++;
            maxi = max(maxi, freq[s[i]-'A']);
            if (i-j+1-maxi > k) {
                freq[s[j]-'A']--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
