class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // TC: O(N), SC: O(1)
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                right--;
            }
            else if (sum == target) {
                break;
            }
            else {
                left++;
            }
        }
        return {left+1, right+1};
    }
};
