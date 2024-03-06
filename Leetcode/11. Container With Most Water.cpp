class Solution {
public:
    int maxArea(vector<int>& height) {
        // TC: O(N), SC: O(1)
        int left = 0, right = height.size() - 1, ans = 0;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            if (height[left] <= height[right]) left++;
            else right--;
        }
        return ans;
    }
};