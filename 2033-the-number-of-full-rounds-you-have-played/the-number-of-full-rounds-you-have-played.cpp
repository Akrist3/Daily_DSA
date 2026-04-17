class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int h1 = stoi(loginTime.substr(0, 2));
        int m1 = stoi(loginTime.substr(3, 2));
        int h2 = stoi(logoutTime.substr(0, 2));
        int m2 = stoi(logoutTime.substr(3, 2));
        int start = h1 * 60 + m1;
        int end = h2 * 60 + m2;
        if (end < start) end += 1440;        
        start = (start + 14) / 15;
        end = end / 15;    
        return max(0, end - start);
    }
};