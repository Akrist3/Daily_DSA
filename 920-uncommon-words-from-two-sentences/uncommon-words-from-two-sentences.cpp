class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> words;
        string word;

        stringstream ss1(s1);
        while (ss1 >> word) {
            words.push_back(word);
        }

        stringstream ss2(s2);
        while (ss2 >> word) {
            words.push_back(word);
        }

        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            int count = 0;

            for (int j = 0; j < words.size(); j++) {
                if (words[i] == words[j]) {
                    count++;
                }
            }

            if (count == 1) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};