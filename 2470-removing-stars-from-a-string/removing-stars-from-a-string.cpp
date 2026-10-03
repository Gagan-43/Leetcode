#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {   // char comparison
                if (!st.empty()) st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string result = ""; 

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());  // reverse to get correct order
        return result;
    }
};
