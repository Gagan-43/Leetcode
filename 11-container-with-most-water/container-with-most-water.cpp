class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //two pointer approach
        int n = height.size();
        int max_wt = 0;
        int left = 0;
        int right = n-1;

        while(left<right){

            int wid = right - left;
            int ht = min(height[left], height[right]);
            int area = wid*ht;

            max_wt = max(max_wt, area);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_wt;

    }
};