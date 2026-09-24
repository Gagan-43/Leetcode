class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap) {
        int usedDays = 1, currentLoad = 0;
        for (int w : weights) {
            if (currentLoad + w > cap) {
                usedDays++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid; // try smaller capacity
            } else {
                left = mid + 1; // need larger capacity
            }
        }
        return left;
    }
};
