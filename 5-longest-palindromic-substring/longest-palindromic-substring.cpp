class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;   // longest palindrome ka start index
        int end = 0;     // longest palindrome ka end index
        
        for (int i = 0; i < s.size(); i++) {
            char currChar = s[i];   // current character
            
            int left = i;
            int right = i;
            
            // Step 1: Handle duplicate characters (like "aaa")
            while (left >= 0 && s[left] == currChar) {
                left--;
            }
            while (right < s.size() && s[right] == currChar) {
                right++;
            }
            
            // Step 2: Expand around center
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            
            // Step 3: Update longest palindrome
            left++;  // kyunki last decrement extra ho gaya
            if (end - start < right - left) {
                start = left;
                end = right;
            }
        }
        
        // substr(start, length) use karna hota hai
        return s.substr(start, end - start);
    }
};
