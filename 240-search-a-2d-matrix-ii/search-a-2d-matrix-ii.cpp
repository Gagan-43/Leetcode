class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0;
        int c = cols - 1; // top-right se start karna hai

        while (r < rows && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                c--; // left move
            } else {
                r++; // down move
            }
        }
        return false;
    }
};
