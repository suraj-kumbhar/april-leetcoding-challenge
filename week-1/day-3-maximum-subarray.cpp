// Maximum Subarray
// Solution
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)    return nums[0];

        int mid = (n - 1) / 2;
        int lMax = INT_MIN;
        int rMax = INT_MIN;
        int sum = 0;
        for (int i = mid + 1; i < n; i++) {
            sum += nums[i];
            rMax = max(rMax, sum);
        }
        sum = 0;
        for (int i = mid; i >= 0; i--) {
            sum += nums[i];
            lMax = max(lMax, sum);
        }
        vector<int> l(nums.begin(), nums.begin() + mid + 1);
        vector<int> r(nums.begin() + mid + 1, nums.end());
        return max({maxSubArray(l), maxSubArray(r), lMax + rMax});
    }
};