class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // rows
        int n = matrix[0].size(); // column

        int st = 0;
        int end = m * n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            int row = mid / n;
            int column = mid % n;

            if (matrix[row][column] > target) {
                end = mid - 1;
            } else if (matrix[row][column] < target) {
                st = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};