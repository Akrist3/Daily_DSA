class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int sum = 0;
        int num = 1;

        while (st.size() < n) {
            if (st.find(k - num) == st.end()) {
                st.insert(num);
                sum += num;
            }
            num++;
        }

        return sum;
    }
};