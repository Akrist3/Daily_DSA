class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l= 0 ,r = 1; // left = buy , right = sell;
        int maxp = 0;
        int n = prices.size();
        while(r< n ){
            if( prices[l] < prices[r]){
                int profit = prices[r]- prices[l];
                maxp = max(maxp,profit);
            }
            else l =r;
            r+=1;

        }
        return maxp;
        
    }
};