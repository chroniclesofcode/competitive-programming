#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

void solve() {  

    LL mod = 1e9 + 7;

    LL t, k;
    cin >> t >> k;


    // dp[i] represents the number of combinations
    // for i amount of flowers
    LL n = 1e5 + 1;
    vector<LL> dp(n, 0);
    for (LL i = 1; i < k; i++) {
        dp[i] = 1;
    }
    dp[k] = 2;
    
    /*
       first case:
       dp[i-1] + a red on the end works
       second case:
       white needs k-1 whites, then a red, then dp[i-k]
       [...][k-1]W all sums to i -> i - k
    */
    for (LL i = k+1; i < n; i++) {
        dp[i] = (dp[i-1] + dp[i-k]) %mod;
    }

    /*
    for (LL i = 0; i < 7; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    */

    // prefix sum of DP to calculate the range
    for (LL i = 1; i < n; i++) {
        dp[i] += dp[i-1];
        dp[i] = dp[i] % mod;
    }

    while (t--) {
        LL a, b;
        cin >> a >> b;
        LL ret = (dp[b] - dp[a-1]) % mod;
        ret = ret < 0 ? ret + mod : ret;
        cout << ret << '\n';
    }
 
    
}

