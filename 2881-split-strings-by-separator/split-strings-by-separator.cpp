class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        for (string word : words) {
            string temp = "";            
            for (char ch : word) {
                if (ch == separator) {
                    if (temp != "") {
                        result.push_back(temp);
                        temp = "";
                    }
                } else {
                    temp += ch;
                }
            }            
            if (temp != "") {
                result.push_back(temp);
            }
        }        
        return result;
    }
};