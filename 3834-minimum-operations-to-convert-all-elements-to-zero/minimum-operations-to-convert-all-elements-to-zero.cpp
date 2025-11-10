class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n =nums.size();
        int ans = 0;
        stack<int> st;

        for (int num : nums) {
            // Pop larger values
            while (!st.empty() && st.top() > num)
                st.pop();

            // If stack is empty or top < current, and current != 0
            if ((st.empty() || st.top() < num) && num != 0) {
                ans++;
                st.push(num);
            }
        }

        return ans;
    }
};