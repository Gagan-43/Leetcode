class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //optimal
        int j=0; //next position for non zero

        for(int i=0;i<nums.size(); i++){
            if(nums[i] !=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        //brute force approach
    //    int n=nums.size();
    //     vector<int> temp;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]!=0){
    //             temp.push_back(nums[i]);
    //         }
    //     }
    //     int nz=temp.size();
    //     for(int i=0;i<nz;i++){
    //         nums[i]=temp[i];
    //     }
    //     for(int i=nz;i<n;i++){
    //         nums[i]=0;
    //     }
    }
};