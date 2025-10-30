class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> seen;
        for (char c : s) {
            if (seen.count(c))  // if already present
                return c;       // this is the first repeated
            seen.insert(c);     // otherwise add to set
        }
        return '0'; // just in case, though problem guarantees one exists
    }
};
