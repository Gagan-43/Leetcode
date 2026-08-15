class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int resXor=0;
        bool allZero=true;

        for(int i=0;i<n;i++){
            resXor=resXor^nums[i];

            if(nums[i]!=0){//we found at least one element which is non zero so allzero = false 
                allZero=false;
            }
        }
        if(allZero){//we can't take any subsequene
            return 0;
        }
        return (resXor==0) ?n-1:n;

    }
};