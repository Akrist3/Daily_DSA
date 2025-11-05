class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // Sort the three values
        vector<int> piles = {a, b, c};
        sort(piles.begin(), piles.end());
        a = piles[0];
        b = piles[1];
        c = piles[2];
        
        if (c >= a + b)
            return a + b;
        else
            return (a + b + c) / 2;
    }
};
