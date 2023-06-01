#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5100;
//const LL MOD = 1e7;

vector<vector<LL>> dp(MX, vector<LL>(MX, INT_MAX));
string a, b;

/*

*/

void solve() {
    cin >> a >> b;
    dp[0][0] = 0;
    dp[1][1] = 0;
    LL as = a.size();
    LL bs = b.size();

    for (LL i = 0; i < bs; i++) 
        dp[0][i+1] = i+1;
    for (LL i = 0; i < as; i++) 
        dp[i+1][0] = i+1;
    
    for (LL i = 0; i < as; i++) {
        for (LL j = 0; j < bs; j++) {
            dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + 1; 
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + (a[i] != b[j]));
            //cout << dp[i+1][j+1] << " ";
        }
        //cout << endl;
    }
    
    cout << dp[as][bs] << endl;
}





