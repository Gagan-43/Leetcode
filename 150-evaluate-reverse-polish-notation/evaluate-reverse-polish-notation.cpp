class Solution {
public:
    int Operate(int a, int b, string token) {
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        if (token == "/") return a / b;
        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                //top 2 elements ko pop krke operate krlo
                //then push in stack the result
                int b = st.top(); st.pop();  // second operand
                int a = st.top(); st.pop();  // first operand
                int result = Operate(a, b, token);
                st.push(result);
            } else {
                st.push(stoi(token));  // convert string to int
            }
        }
        return st.top();
    }
};
