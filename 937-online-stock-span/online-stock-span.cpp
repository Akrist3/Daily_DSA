class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind = -1;
    StockSpanner() {
        ind = -1;
    }
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans;
        if(st.empty()){
            ans = ind + 1;
        } else {
            ans = ind - st.top().second;
        }
        st.push({price, ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */