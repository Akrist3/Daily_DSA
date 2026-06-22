class Solution {
public:
    void sortColors(vector<int>& num) {
        int n = num.size();
        int one = 0,zero = 0,to = 0;
        for(int i = 0;i<n;i++){
            if(num[i] == 0) zero++;
            else if(num[i] == 1) one++;
            else to++;
        }
        int ind =0;
        while(zero--) num[ind++] = 0;
        while(one--)  num[ind++] = 1;
        while(to--)  num[ind++] = 2;
    }
};