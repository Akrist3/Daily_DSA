class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for (int a : ast) {
            bool destroyed = false;
            // Collision occurs only if:
            // top > 0 and current a < 0
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();           // top is smaller → destroyed
                    continue;
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();           // both destroy each other
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;   // current a is destroyed
                    break;
                }
            }
            if (!destroyed) {
                st.push(a);
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
