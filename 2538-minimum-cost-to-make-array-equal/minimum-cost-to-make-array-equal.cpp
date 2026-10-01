class Solution {
public:
    typedef long long ll;

    ll findCost(vector<int>& nums, vector<int>& cost, int target) {
        ll result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += (ll)abs(nums[i] - target) * cost[i];
        }
        return result;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll answer = LLONG_MAX;

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;

            ll cost1 = findCost(nums, cost, mid);
            ll cost2 = findCost(nums, cost, mid + 1);

            answer = min(answer, min(cost1, cost2));

            // Binary search adjustment
            if (cost1 < cost2) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};
