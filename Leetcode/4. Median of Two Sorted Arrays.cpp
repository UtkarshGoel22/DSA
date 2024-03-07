class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // TC: O(log (m+n)), SC: O(1)
        if (nums1.size() > nums2.size()) nums1.swap(nums2);
        int n = nums1.size(), m = nums2.size(), splitSize = (n + m) / 2;
        int low = 0, high = n; // binary search on smaller array.
        double ans;
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = splitSize - cut1;
            double l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            double l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            double r1 = cut1 == n ? INT_MAX : nums1[cut1];
            double r2 = cut2 == m ? INT_MAX : nums2[cut2];
            if (l1 > r2) high = cut1-1;
            else if (l2 > r1) low = cut1+1;
            else {
                ans = (n+m) % 2 ? min(r1,r2) : (max(l1,l2) + min(r1, r2))/2;
                break;
            }
        }
        return ans;
    }
};
