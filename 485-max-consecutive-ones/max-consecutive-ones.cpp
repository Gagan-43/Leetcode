class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;     // abhi tak ke consecutive 1s ka count
    int maxCount = 0;  // sabse bada consecutive 1s ka count

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            count++;  // agar 1 mila toh count badhao
            if(count > maxCount){
                maxCount = count; // maxCount update karo agar naya bada sequence mila
            }
        }
        else{
            count = 0; // agar 0 mila toh sequence break ho gaya, count reset
        }
    }
    return maxCount; // sabse bada consecutive 1s ka sequence return karo

    }
};