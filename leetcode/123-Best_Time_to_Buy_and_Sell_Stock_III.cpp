class Solution {
public:
        int hold[100001][3];
        int free[100001][3];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();   
        hold[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            hold[i][1] = max(hold[i-1][1], free[i-1][0] - prices[i]);
            free[i][1] = max(free[i-1][1], hold[i-1][1] + prices[i]);
            if (free[i-1][1] > 0) {
                hold[i][2] = max(hold[i-1][2], free[i-1][1] - prices[i]);
                free[i][2] = max(free[i-1][2], hold[i-1][2] + prices[i]);
            } else {
                if (i+1 < n) {
                    hold[i][2] = -prices[i+1];
                }
            }
            /*
            cout << "hold[" << i << "][1] = " << hold[i][1] << endl;
            cout << "free[" << i << "][1] = " << free[i][1] << endl;
            cout << "hold[" << i << "][2] = " << hold[i][2] << endl;
            cout << "free[" << i << "][2] = " << free[i][2] << endl;
            cout << endl;
            */
        }
        return max({0, free[n-1][2], free[n-1][1]});
    }
};
