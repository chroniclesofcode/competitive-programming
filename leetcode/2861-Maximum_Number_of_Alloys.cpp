class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& comp, vector<int>& stock, vector<int>& cost) {
        #define LL long long
        // n = types of alloys, k = machines -> for each machine, just check how many alloys we can force-create.
        LL ans = 0;
        for (int i = 0; i < k; i++) { // each machine
            LL create = 0;
            int lo = 0; int hi = (int)1e9 + 1;
            while (lo <= hi) {
                LL mid = lo + (hi - lo)/2;
                LL cash = budget;
                for (int j = 0; j < n; j++) { // each alloy in machine, try to create mid amount
                    cash -= (mid * comp[i][j] - min((LL)stock[j], mid*(LL)comp[i][j])) * cost[j];
                }
                if (cash >= 0) {
                    ans = max(ans, mid);
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
        }
        return ans;
    }
};
