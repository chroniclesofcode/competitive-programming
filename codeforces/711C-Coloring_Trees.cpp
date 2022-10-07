#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long
#define INFIN numeric_limits<LL>::max() / 2

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

const LL MX = 120;
LL dp[MX][MX][MX];
LL color[MX];
LL cost[MX][MX];
vector<vector<vector<pair<LL, LL>>>> minlist(MX, vector<vector<pair<LL, LL>>>(MX, vector<pair<LL, LL>>()));

void Debug(LL n, LL m, LL k) {
    for (LL i = 0; i < n; i++) {
        cout << "i = " << i << endl;
        for (LL j = 1; j <= k; j++) {
            cout << "    j = " << j << endl;
            cout << "        ";
            for (LL t = 0; t < m; t++) {
                if (dp[i][j][t] == numeric_limits<LL>::max()) {
                    cout << -1 << " ";
                } else {
                    cout << dp[i][j][t] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

void process(pair<LL, LL> &first, pair<LL, LL> &second, LL &a, LL &b, LL &c) {
    if (dp[a][b][c] <= first.first) {
        second = first;
        first.first = dp[a][b][c];
        first.second = c;
    } else if (dp[a][b][c] < second.first) {
        second.first = dp[a][b][c];
        second.second = c;
    }
}

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    for (LL i = 0; i < n; i++) {
        cin >> color[i];
    }

    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    /*
       dp[i][j] represents min cost for 0..i trees
       with j beauty and color k on that SPECIFIC tree...
       going to be O(nmk), which is fine because of bounds

    */
    for (LL a = 0; a < n; a++) {
        for (LL b = 0; b <= k; b++) {
            for (LL c = 0; c < m; c++) {
                dp[a][b][c] = INFIN;
            }
        }
    }
    for (LL a = 0; a < n; a++) {
        for (LL b = 0; b <= k; b++) {
            LL diff = INFIN;
            LL same = INFIN;
            pair<LL, LL> first = { INFIN, 110 };
            pair<LL, LL> second = { INFIN, 110 };
            for (LL c = 0; c < m; c++) {
                if (b == 0) continue;
                if (b > a + 1) {
                    process(first, second, a, b, c);
                    continue;
                }
                if (a == 0 && b == 1) {
                    if (color[a] == 0) {
                        dp[a][b][c] = cost[a][c];
                    } else {
                        dp[a][b][color[a]-1] = 0;
                    }
                    process(first, second, a, b, c);
                    continue;
                } 
                
                
                if (color[a] == 0) {
                    // we choose this current colour c
                    // then for this case, we are saying
                    // we will make it the same as the previous
                    dp[a][b][c] = min(dp[a][b][c], dp[a-1][b][c] + cost[a][c]);

                    // We will make it different from the previous
                    // which means we need the minimum dp a-1 b-1 c
                    // that is NOT equal to our current c
                    LL mincol = minlist[a-1][b-1][0].second == c ? minlist[a-1][b-1][1].first : minlist[a-1][b-1][0].first;
                    dp[a][b][c] = min(dp[a][b][c], mincol + cost[a][c]);
                    /*
                    for (LL g = 0; g < m; g++) {
                        if (g != c)
                            dp[a][b][c] = min(dp[a][b][c], dp[a-1][b-1][g] + cost[a][c]);
                        //cout << dp[a-1][b-1][g] << " " << a << b << c << g << endl;
                    }
                    */
                } else {
                    // Same as above... but with no extra cost basically
                    dp[a][b][color[a]-1] = min(dp[a][b][color[a]-1], dp[a-1][b][color[a]-1]);
                    LL mincol = minlist[a-1][b-1][0].second == color[a]-1 ? minlist[a-1][b-1][1].first : minlist[a-1][b-1][0].first;
                    //cout << "mincol: " << minlist[a-1][b-1][0].second << " " << minlist[a-1][b-1][1].second << " " << a << b << c << endl;
                    dp[a][b][color[a]-1] = min(dp[a][b][color[a]-1], mincol);
                    /*
                    for (LL g = 0; g < m; g++) {
                        if (g != color[a]-1)
                            dp[a][b][color[a]-1] = min(dp[a][b][color[a]-1], dp[a-1][b-1][g]);
                    }
                    */
                }
                process(first, second, a, b, c);
               
            }
            minlist[a][b].push_back(first);
            minlist[a][b].push_back(second);
        }
    }
    //Debug(n, m, k);

    LL ret = INFIN;
    for (LL i = 0; i < m; i++) {
        ret = min(ret, dp[n-1][k][i]);
    }
    if (ret >= INFIN) {
        ret = -1;
    }
    
    cout << ret << '\n';

}

