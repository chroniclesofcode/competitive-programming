#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

const LL MAXSZ = 1e5 + 20;
LL r1[MAXSZ];
LL r2[MAXSZ];


void solve() {
    LL n;
    cin >> n;
    for (LL i = 0; i < n; i++) cin >> r1[i];
    for (LL i = 0; i < n; i++) cin >> r2[i];
    
    /*
   //DP problem
   //we are going to have a 2d array 
   
   //dp[i][0] and dp[i][1] represents the max total height
   //IF the ith student in the 1st or 0th row is selected.
   //We will also keep track of the max height while we're at it.

   //Note I guess these will also consider NOT selecting the current
   //one as well
   */

    vector<vector<LL>> dp(n, vector<LL>(2, 0));
    dp[0][0] = r1[0];
    dp[0][1] = r2[0];
    LL ret = max(dp[0][0], dp[0][1]);

    for (LL i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][1]+r1[i], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0]+r2[i], dp[i-1][1]);
        ret = max(ret, dp[i][0]);
        ret = max(ret, dp[i][1]);
    }
    cout << ret << '\n';
}

