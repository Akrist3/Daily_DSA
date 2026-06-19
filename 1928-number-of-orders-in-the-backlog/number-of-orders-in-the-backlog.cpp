class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MOD = 1e9 + 7;

        // buy: max heap {price, amount}
        priority_queue<pair<int,int>> buy;

        // sell: min heap {price, amount}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > sell;

        for(auto &order : orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];

            if(type == 0) { // buy order

                while(amount > 0 && !sell.empty() &&
                      sell.top().first <= price) {

                    auto [sPrice, sAmount] = sell.top();
                    sell.pop();

                    int matched = min(amount, sAmount);

                    amount -= matched;
                    sAmount -= matched;

                    if(sAmount > 0)
                        sell.push({sPrice, sAmount});
                }

                if(amount > 0)
                    buy.push({price, amount});
            }
            else { // sell order

                while(amount > 0 && !buy.empty() &&
                      buy.top().first >= price) {

                    auto [bPrice, bAmount] = buy.top();
                    buy.pop();

                    int matched = min(amount, bAmount);

                    amount -= matched;
                    bAmount -= matched;

                    if(bAmount > 0)
                        buy.push({bPrice, bAmount});
                }

                if(amount > 0)
                    sell.push({price, amount});
            }
        }

        long long ans = 0;

        while(!buy.empty()) {
            ans = (ans + buy.top().second) % MOD;
            buy.pop();
        }

        while(!sell.empty()) {
            ans = (ans + sell.top().second) % MOD;
            sell.pop();
        }

        return ans;
    }
};