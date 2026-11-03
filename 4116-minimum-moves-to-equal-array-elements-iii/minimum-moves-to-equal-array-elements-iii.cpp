class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        int n = nums.size();
        int last = nums[n - 1];


        for (int i = 0; i < n; i++) {
            int count = last - nums[i];
            res += count;
        }
        return res;
    }
};