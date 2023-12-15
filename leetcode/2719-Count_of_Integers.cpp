class Solution {
public:
    #define LL long long
    LL dp[24][2][250];
    static const int md = (int)1e9 + 7;
    LL query(string &ss, int mis, int mas) {
        int n = ss.size();
        memset(dp, 0, sizeof(dp));
        dp[n][0][0] = 1;
        dp[n][1][0] = 1;
        for (int i = n-1; i >= 0; i--) {
            for (int tight = 0; tight < 2; tight++) {
                for (int sum = 0; sum <= 220; sum++) {
                    if (tight) {
                        for (int d = 0; d <= ss[i]-'0'; d++) {
                            if (sum >= d)
                            dp[i][1][sum] += (d == ss[i]-'0') ? dp[i+1][1][sum-d] : dp[i+1][0][sum-d];
                            dp[i][1][sum] %= md;
                        }
                    } else {
                        for (int d = 0; d < 10; d++) {
                            if (sum >= d)
                                dp[i][0][sum] += dp[i+1][0][sum-d];
                                dp[i][0][sum] %= md;
                        }
                    }
                }
            }
        }
        LL ans = 0;
        for (int i = mis; i <= min(249,mas); i++) {
            ans += dp[0][1][i];
        }
        return ans % md;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        LL ans = query(num2, min_sum, max_sum) - query(num1, min_sum, max_sum);
        int sdg = 0;
        for (int i = 0; i < num1.size(); i++) sdg += num1[i]-'0';
        if (sdg >= min_sum && sdg <= max_sum) ans++;
        return (ans%md+md)%md;
    }
};
