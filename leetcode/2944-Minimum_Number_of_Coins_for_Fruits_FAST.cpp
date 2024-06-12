class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        int coins = 0;
        int inf = (int)1e9;
        // dp[i] = min cost to obtain this fruit
        vector<int> dp(n);
        deque<int> dq;
        dp[0] = prices[0];
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!dq.empty() && (dq.front()+1)*2 < i+1)
                dq.pop_front();
            while (!dq.empty()) {
                int bk = dq.back();
                int before = (bk == 0) ? 0 : dp[bk-1];
                if (dp[i-1] + prices[i] <= before + prices[bk]) {
                    dq.pop_back();
                } else {
                    break;
                }
            }
            dq.push_back(i);
            int fr = dq.front();
            int before = fr == 0 ? 0 : dp[fr-1];
            dp[i] = before + prices[fr];
        }

        return dp[n-1];
    }
};
