class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";   // agar string empty hai to return ""
        
        int start = 0;              // longest palindrome ka starting index
        int maxLen = 1;             // longest palindrome ki length (minimum 1 hamesha hoti hai)
        
        // Har character ko center maan ke expand karenge
        for (int i = 0; i < s.size(); i++) {
            // Odd length palindrome (center ek character)
            expandAroundCenter(s, i, i, start, maxLen);
            
            // Even length palindrome (center do characters)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }
        
        // longest palindrome substring return karo
        return s.substr(start, maxLen);
    }
    
private:
    // Helper function jo center se expand karta hai
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen) {
        // Jab tak left aur right valid hai aur characters match karte hain
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            // Agar naya palindrome bada hai to update karo
            if (right - left + 1 > maxLen) {
                start = left;                   // naya start index
                maxLen = right - left + 1;      // nayi length
            }
            left--;   // left side expand karo
            right++;  // right side expand karo
        }
    }
};

        