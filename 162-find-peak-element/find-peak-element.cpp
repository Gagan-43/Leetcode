class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;

        while(low<high){
            mid=low+(high-low)/2;//formula
            if(nums[mid]>nums[mid+1]){
                high=mid;//q ki mid bada hai vo right side ki trf jaega isliye vo high me store hoga
            }
            else{
                low=mid+1;//q ki mid chota hai vo left side ki or jaega islie
            }
        }
        return low;//hum high ko vi return kr skte hai q ki jb ye loop se bhr aayenge toh dono equal index par honge means peak element find 
    }
};