class Solution {
public:
    int maxSubArray(vector<int>& num) {
        int n = num.size();
        int sum = 0,maxi = num[0];
        for(int i = 0;i<n;i++){
            sum += num[i];
            if(sum > maxi){
                maxi = sum;
        }
        if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
