class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        for(char c : s) {
            if(c == '(') {
                st.push(0);   // marker for new frame
            } else {
                int top = st.top();
                st.pop();
                if(top == 0) {
                    st.push(1);   // "()" → score = 1
                } else {
                    st.push(2 * top);  // "(A)" → 2*A
                }

                // Merge only after closing a frame
                if(st.size() > 1) {
                    int val = st.top();
                    st.pop();
                    st.top() += val;   // AB → A + B
                }
            }
        }

        return st.top();
    }
};
