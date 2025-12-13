#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        string vowels = "aeiou";
        int maxVowel = 0, maxConsonant = 0;

        for (auto &p : freq) {
            if (vowels.find(p.first) != string::npos)
                maxVowel = max(maxVowel, p.second);
            else
                maxConsonant = max(maxConsonant, p.second);
        }

        return maxVowel + maxConsonant;
    }
};
