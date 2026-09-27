// LeetCode 374: Guess Number Higher or Lower
// API guess(int num) is already defined in the problem

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while (l <= r) {
            int guess_no = l + (r - l) / 2;   // mid point

            int val = guess(guess_no);        // call API

            if (val == 0) {
                return guess_no;              // found the number
            } else if (val == -1) {
                r = guess_no - 1;             // target is smaller
            } else {
                l = guess_no + 1;             // target is larger
            }
        }
        return -1; // should never reach here
    }
};
