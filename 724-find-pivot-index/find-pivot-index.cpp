class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int x = 0; x < nums.size(); x++) {
            sum += nums[x];
        }

        int left = 0;
        for (int i = 0; i < nums.size(); i++) {   // <-- loop 0 se start karo
            int right = sum - left - nums[i];

            if (left == right) {
                return i;
            }
            left += nums[i];   // <-- update left after checking
        }
        return -1;
    }
};
