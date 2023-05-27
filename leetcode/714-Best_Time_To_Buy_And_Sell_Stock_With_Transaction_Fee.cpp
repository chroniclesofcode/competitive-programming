class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0;
        int n = prices.size();
        vector<int> freed(n, 0);
        vector<int> hold(n, 0);
        hold[0] = -prices[0]; // max profit - we need to buy first day

        for (int i = 1; i < n; i++) {
            freed[i] = max(freed[i-1], hold[i-1]+prices[i]-fee);
            hold[i] = max(freed[i-1]-prices[i], hold[i-1]);
        }   
        return freed[n-1];
    }
};
