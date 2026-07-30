class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closest = INT_MAX;
        int res_sum = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // Update the closest sum
                if (abs(target - sum) < closest) {
                    closest = abs(target - sum);
                    res_sum = sum;
                }

                // If exact target is found
                if (sum == target) {
                    return sum;
                }
                else if (sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return res_sum;
    }
};