class MinStack {
    vector<pair<int, int>> st;
public:
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push_back({value, value});
        } else {
            st.push_back({value, min(value, st.back().second)});
        }
    }

    void pop() { st.pop_back(); }

    int top() { return st.back().first; }

    int getMin() { return st.back().second; }
};
