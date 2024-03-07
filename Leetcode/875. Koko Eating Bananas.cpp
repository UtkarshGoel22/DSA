class Solution {
    bool check(vector<int>& piles, int h, int mid) {
        int hours = 0, n = piles.size();
        for (int i = 0; i < n; i++) {
            hours += piles[i]/mid + (piles[i]%mid ? 1 : 0);
            if (hours > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // TC: O(NlogN), SC: O(1)
        int low = 1, high = 1e9, ans;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (check(piles, h, mid)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};
