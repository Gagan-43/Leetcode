class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;//res = 0 se start karte ho.
        //xor method
       for (int i = 0; i < nums.size(); i++) {
           res = res ^ i ^ nums[i];//Har index i aur uske corresponding number nums[i] ko XOR karte ho.
           //Matlab tum simultaneously 0..n ke indices aur array ke actual numbers ko XOR kar rahe ho.
        }
        return res ^ nums.size();//Loop ke baad ek extra XOR karte ho nums.size() ke saath (jo n hota hai).
//Jo number cancel nahi hota, wahi missing number hota hai.
    }
};








