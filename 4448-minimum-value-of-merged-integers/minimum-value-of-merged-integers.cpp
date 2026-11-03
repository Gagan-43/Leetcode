class Solution {
public:
int fun(int num){
            int count=0;
            if(num==0){
                count=1;
            }
            else{
                while(num!=0){
                    num=num/10;
                    count++;
                }
            }
        return count;
    }     
    int minMergedInteger(vector<int>& nums) {
        
        vector<int> res;
        for(int i=0;i<nums.size();i+=2){
            int g=fun(nums[i+1]);
            res.push_back(nums[i]*pow(10,g)+nums[i+1]);
        }
        sort(res.begin(),res.end());
        return res[0];
    }
};