class Solution {
public:
    // Helper function: check karo ki substring palindrome hai ya nahi
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){   // agar mismatch mila toh false
                return false;
            }
            left++;    // left pointer aage badhao
            right--;   // right pointer peeche le jao
        }
        return true;   // agar pura loop bina mismatch ke complete ho gaya toh palindrome
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            if(s[left] != s[right]){  
                // agar mismatch mila toh ek character delete karne ka chance hai
                // ya toh left skip karo ya right skip karo
                return isPalindrome(s, left+1, right) || 
                       isPalindrome(s, left, right-1);
            }
            left++;
            right--;
        }
        return true; // agar loop complete ho gaya bina mismatch ke toh palindrome hai
    }
};
