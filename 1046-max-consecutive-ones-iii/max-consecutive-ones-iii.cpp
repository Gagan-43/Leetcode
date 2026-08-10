class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int zerocnt=0;
        int n=nums.size();

        for(int right=0;right<n;right++){
           if(nums[right]==0){
            zerocnt++;
           }
           if(zerocnt>k){
            if(nums[left]==0){
                zerocnt--;
            }
            left++;
           }
        }
        return n-left;
    }
};