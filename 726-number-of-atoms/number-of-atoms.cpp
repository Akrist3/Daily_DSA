class Solution {
public:
    string countOfAtoms(string s) {
        stack<map<string, int>> st;
        st.push({});

        for (int i = 0; i < s.size(); ) {
            if (s[i] == '(') {
                st.push({});
                i++;
            }
            else if (s[i] == ')') {
                i++;
                int k = 0;
                while (i < s.size() && isdigit(s[i]))
                    k = k * 10 + (s[i++] - '0');
                if (k == 0) k = 1;

                auto cur = st.top();
                st.pop();
                for (auto &x : cur)
                    st.top()[x.first] += x.second * k;
            }
            else {
                string atom;
                atom += s[i++];
                while (i < s.size() && islower(s[i]))
                    atom += s[i++];

                int k = 0;
                while (i < s.size() && isdigit(s[i]))
                    k = k * 10 + (s[i++] - '0');
                if (k == 0) k = 1;

                st.top()[atom] += k;
            }
        }

        string ans;
        for (auto &x : st.top()) {
            ans += x.first;
            if (x.second > 1) ans += to_string(x.second);
        }
        return ans;
    }
};
