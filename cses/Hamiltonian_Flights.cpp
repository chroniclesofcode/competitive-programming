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
#define NINF -INF

const LL MX = 25;
const LL MOD = 1e9+7;

int n, m, vis[MX], dp[(1 << 20) + 10][MX];
vector<int> rev[MX];
int LG = 1;
/*

*/


void solve() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        //adj[a][b]++;
        //adj[a].push_back(b);
        rev[b].push_back(a);
    }
    LG = 1 << n;
    /*
       The below case might seem like a decent
       starting case, but not really valid since
       1 is not included in the paths except the first.

       It seems like it won't be considered, but consider
       00011 -> we're going to run DP on 00010 excluding
       the first node (origin), which is going to give 1 if we use the
       case below. In fact, we want to use 0, since 00010
       doesn't have 1 in it!
    */
    /*
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 1;
    }
    */
    dp[1][0] = 1;
    for (int i = 2; i < LG; i++) {
        // Doesn't include 1st city, exclude
        if (!(i & 1)) continue;
        // SINCE hamilton path, you need to include
        // all cities in order to be able to add on
        // the very last city (don't want to add on
        // dp with last city when not all vertices visited.
        if (i & (1 << (n-1)) && i != LG-1) continue;
        for (int j = 0; j < n; j++) {
            // Is in the subset
            int u = 1 << j;
            if (i & u) {
                // For every v which is linked to u
                // check if it is in the subset
                // and compute dp
                for (auto &k : rev[j]) {
                    int v = 1 << k;
                    if (i & v) {
                        dp[i][j] += dp[i^u][k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
    }
    cout << dp[LG-1][n-1] << endl;
}





