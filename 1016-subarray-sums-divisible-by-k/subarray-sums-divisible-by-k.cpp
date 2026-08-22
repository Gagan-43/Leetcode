class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        mp[0] = 1;

        int count = 0;
        int pS = 0;

        for(int i = 0; i < nums.size(); i++) {
            
            pS += nums[i];

            int rem = pS % k;

            // Negative remainder ko positive banane ke liye
            if(rem < 0) {
                rem += k;
            }

            // Same remainder pehle mila hai
            if(mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            // Remainder store karo
            mp[rem]++;
        }

        return count;
    }
};