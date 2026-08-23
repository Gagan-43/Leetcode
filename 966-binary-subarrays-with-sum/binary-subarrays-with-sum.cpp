class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        unordered_map<int,int>mp;
        mp[0]=1;

        int sum=0;
        int count=0;

        for(int x=0;x<n;x++){
            sum+=nums[x];

            if(mp.find(sum-goal)!=mp.end()){
                count+=mp[sum-goal];
            }
            mp[sum]++;
        }
        return count;
    }
};