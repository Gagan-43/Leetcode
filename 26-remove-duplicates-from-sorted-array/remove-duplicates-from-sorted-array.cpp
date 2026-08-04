class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int k=1; // pehla element hamesha unique hoga
        for(int i=1;i<nums.size();i++){ // i=1 se start karo
            if(nums[i]!=nums[i-1]){     // current aur previous compare karo
                nums[k]=nums[i];        // unique element ko k-th position pe daalo
                k++;
            }
        }
        return k;
    }
};
