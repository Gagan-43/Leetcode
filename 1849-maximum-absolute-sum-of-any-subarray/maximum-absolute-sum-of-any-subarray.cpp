class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int currMax = 0, currMin = 0;

        for (int x : nums) {
            // Kadane for max sum
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            // Kadane for min sum
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);
        }

        return max(abs(maxSum), abs(minSum));
    }
};
