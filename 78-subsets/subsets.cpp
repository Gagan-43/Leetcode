class Solution {
public:

    void fun1(vector<int>& nums, int i, vector<int>& temp,vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(temp);
            return;
        }
        fun1(nums, i + 1, temp, res);
        temp.push_back(nums[i]);

        fun1(nums, i + 1, temp, res);
        temp.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        fun1(nums, 0, temp, res);
        return res;
    }
};