class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        unordered_map<int, int> mp;  // ✅ Correct declaration

        while (j < n) {
            // If window size exceeds k, shrink from left
            if (j - i > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            // If duplicate found in current window
            if (mp.find(nums[j]) != mp.end()) {
                return true;
            }

            mp[nums[j]]++;  // Add current element to map
            j++;
        }
        return false;
    }
};
