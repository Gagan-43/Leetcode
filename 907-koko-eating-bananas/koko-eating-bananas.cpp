class Solution {
public:
    bool canEat(vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed; // ceil(pile/speed)
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canEat(piles, mid, h)) {
                ans = mid;       // possible, try smaller
                right = mid - 1;
            } else {
                left = mid + 1;  // not possible, need bigger speed
            }
        }
        return ans;
    }
};
