class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;                     // left pointer
        int right = height.size() - 1;    // right pointer
        int leftMax = 0, rightMax = 0;    // max height seen so far from left & right
        int water = 0;                    // total trapped water

        // jab tak left aur right cross nahi karte
        while (left <= right) {
            // agar left side chhoti hai, toh left process karo
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    // agar current height bada hai, update leftMax
                    leftMax = height[left];
                } else {
                    // otherwise water trap hoga = leftMax - current height
                    water += leftMax - height[left];
                }
                left++; // left pointer aage badhao
            } 
            else {
                // agar right side chhoti hai, toh right process karo
                if (height[right] >= rightMax) {
                    // agar current height bada hai, update rightMax
                    rightMax = height[right];
                } else {
                    // otherwise water trap hoga = rightMax - current height
                    water += rightMax - height[right];
                }
                right--; // right pointer peeche le jao
            }
        }
        return water; // total trapped water return karo
    }
};
