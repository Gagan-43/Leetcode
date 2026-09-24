class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for (int b : bloomDay) {
            if (b <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // reset streak
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m * k;
        if (total > bloomDay.size()) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1; // try earlier day
            } else {
                left = mid + 1; // need later day
            }
        }
        return ans;
    }
};
