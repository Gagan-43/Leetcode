class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += expand(s, i, i);       // odd-length palindromes
            count += expand(s, i, i + 1);   // even-length palindromes
        }

        return count;
    }

private:
    int expand(string &s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }
};
