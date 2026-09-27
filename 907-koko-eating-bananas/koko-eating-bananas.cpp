class Solution {
public:
    bool canEatAll(vector<int>& piles, int mid, int h) {
        int actualHours = 0;

        for (int x : piles) {
            actualHours += x / mid;   // base hours//x-> kitne banana hai ek pile me
            if (x % mid != 0) {
                actualHours++;        // extra hour if remainder
            }
        }
        return actualHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2; // per hour speed// per hour i can eat mid number of piles

            if (canEatAll(piles, mid, h)) {
                r = mid;   // try smaller speed
            } else {
                l = mid + 1; // need bigger speed
            }
        }
        return l;
    }
};
