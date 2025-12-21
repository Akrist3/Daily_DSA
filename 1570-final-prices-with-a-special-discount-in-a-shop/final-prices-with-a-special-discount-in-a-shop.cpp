class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            ans[i] = prices[i] - (st.empty() ? 0 : st.top());
            st.push(prices[i]);
        }
        return ans;
    }
};
