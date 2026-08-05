class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n); // final result vector banaya, size same as input
        
        int left = 0;          // left pointer start mein rakha
        int right = n - 1;     // right pointer end mein rakha
        int idx = n - 1;       // result vector ke last index se fill karna start karenge
        
        // Jab tak left <= right hai tab tak loop chalega
        while (left <= right) {
            int leftSq = nums[left] * nums[left];   // left element ka square
            int rightSq = nums[right] * nums[right]; // right element ka square
            
            // Jo bada square hoga usse result ke end mein daal denge
            if (leftSq > rightSq) {
                res[idx] = leftSq; // bada square daala 
                idx--;//idx ko ek step peeche le gaye
                left++;              // left pointer ko aage badha diya
            } else {
                res[idx] = rightSq; // bada square daala aur idx ko ek step peeche le gaye
                idx--;//idx ko ek step peeche le gaye
                right--;              // right pointer ko peeche le gaye
            }
        }
        
        return res; // final sorted squares return kar diye
    }
};
