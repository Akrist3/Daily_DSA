class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        string num = "";

        for (char ch : word) {
            if (isdigit(ch)) {
                num += ch;
            }
            else {
                if (!num.empty()) {
                    // Remove leading zeros
                    int i = 0;
                    while (i < num.size() && num[i] == '0') {
                        i++;
                    }

                    // If number was "000", it represents 0
                    if (i == num.size())
                        st.insert("0");
                    else
                        st.insert(num.substr(i));

                    num = "";
                }
            }
        }

        // Handle number at the end of string
        if (!num.empty()) {
            int i = 0;
            while (i < num.size() && num[i] == '0') {
                i++;
            }

            if (i == num.size())
                st.insert("0");
            else
                st.insert(num.substr(i));
        }

        return st.size();
    }
};
