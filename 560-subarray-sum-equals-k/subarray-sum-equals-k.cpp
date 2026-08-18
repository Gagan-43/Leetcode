class Solution { 
public: 
    int subarraySum(std::vector<int>& nums, int k) { 
        unordered_map<int, int> mp; 
        int count = 0; 
        int pS = 0; 
        
        // Base case: a prefix sum of 0 has been seen once
        mp[0] = 1; 
        
        for (int n : nums) { 
            pS += n; // Accumulate the running sum
            
            // Check if the required complement exists
            if (mp.find(pS - k) != mp.end()) { 
                count += mp[pS - k]; 
            } 
            
            // Record the current prefix sum in the map
            mp[pS]++; 
        } 
        return count; 
    } 
};