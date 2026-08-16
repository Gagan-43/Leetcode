class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int left=0;

        for(int x=0;x<nums.size();x++){
            sum+=nums[x];
        }
        for(int i=0;i<nums.size();i++){
            int right=sum-left-nums[i];

            if(right==left){
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};