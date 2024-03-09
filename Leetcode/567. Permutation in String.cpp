class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // TC: O(N), SC: O(1)
        int n = s1.length(), m = s2.length();
        // length of string s1 is greater than string s2.
        if (n > m) return false;
        vector<int> freq1(26), freq2(26);
        // calculate frequency of all the characters in string s1
        // and first 0 characters [0-n) in string s2.
        for (int i = 0; i < n; i++) {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        int i = 0, j = n-1, match;
        // iterate over string s2 taking the window size as n (length of string s1).
        while (j < m) {
            match = 0;
            for (int k = 0; k < 26; k++) {
                if (freq1[k] == freq2[k]) match++;
                else break;
            }
            // When frequency of all the characters is same for both 
            // the strings then permutations of s1 exists in s2.
            if (match == 26) return true;
            // exclude leftmost element of the window.
            freq2[s2[i]-'a']--;
            i++, j++;
            // include the next element as part of the window.
            if (j < m) freq2[s2[j]-'a']++;
        }
        return false;
    }
};
