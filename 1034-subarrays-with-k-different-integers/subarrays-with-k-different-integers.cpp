class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        int left = 0, count = 0;
        unordered_map<int, int> mp;

        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            while ((int)mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            count += right - left + 1;
            
        }
        return count;
    }
};
