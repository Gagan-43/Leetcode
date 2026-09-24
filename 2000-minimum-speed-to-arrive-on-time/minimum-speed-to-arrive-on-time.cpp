class Solution {
public:
    bool canArrive(vector<int>& dist, double hour, int speed) {
        double total = 0;
        int n = dist.size();
        for (int i = 0; i < n - 1; i++) {
            total += (dist[i] + speed - 1) / speed; // ceil division
        }
        total += (double)dist[n - 1] / speed;
        return total <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 10000000, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canArrive(dist, hour, mid)) {
                ans = mid;
                right = mid - 1; // try smaller speed
            } else {
                left = mid + 1; // need larger speed
            }
        }
        return ans;
    }
};

