class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);   // string ko '/' ke basis par tokenize karne ke liye
        stack<string> st;        // valid directory names store karne ke liye

        while (getline(ss, token, '/')) {
            // Agar token empty hai ya '.' hai toh skip karo
            if (token == "" || token == ".")
                continue;

            // Agar token '..' nahi hai toh stack me push karo
            if (token != "..") {
                st.push(token);
            } 
            // Agar '..' mila aur stack empty nahi hai toh ek directory pop karo
            else if (!st.empty()) {
                st.pop();
            }
        }

        string result = "";
        // Stack ke elements ko reverse order me result string me add karo
        while (!st.empty()) {
            result = "/" + st.top() + result; // top element ko prepend karo
            st.pop();                         // element remove karo
        }

        // Agar result empty hai toh root '/' return karo
        return result == "" ? "/" : result;
    }
};