class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i] * nums[i]; // har element ka square
        }
        sort(nums.begin(), nums.end()); // sorted order mein arrange karo
        return nums; // final vector return karo
    }
};
