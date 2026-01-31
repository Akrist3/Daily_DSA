class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;
        // Count student preferences
        for (int s : students) {
            if (s == 0) count0++;
            else count1++;
        }
        // Serve sandwiches
        for (int sw : sandwiches) {
            if (sw == 0 && count0 > 0) {
                count0--;
            } 
            else if (sw == 1 && count1 > 0) {
                count1--;
            } 
            else {
                break;  // no one wants this sandwich
            }
        }
        return count0 + count1;
    }
};
