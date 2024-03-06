class Solution {
public:
    bool isPalindrome(string s) {
        // TC: O(N), SC: O(1)
        int n = s.size(), left = 0, right = n-1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};
