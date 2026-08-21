class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        long long leftSum = 0;
        int count = 0;

        // iterate till n-1 because split must leave at least one element on right
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            long long rightSum = totSum - leftSum;

            if (leftSum >= rightSum) {
                count++;
            }
        }
        return count;
    }
};
