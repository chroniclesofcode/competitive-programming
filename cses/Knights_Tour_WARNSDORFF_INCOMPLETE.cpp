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

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

#define arr array<int,2>
int x, y;
int dp[30][30];
int SZ = 8;
/*

*/

vector<vector<int>> dir = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool check(int a, int b) {
    return a >= 1 && b >= 1 && a <= SZ && b <= SZ && dp[a][b] == 0;
}

void solve() {
    cin >> y >> x;
    int a, b, ct = 0;
    for (int i = 1; i <= SZ * SZ; i++) {
        dp[x][y] = i;
        int t1 = x, t2 = y;
        // search for unvisited node with
        // least reachable edges
        int minr = numeric_limits<int>::max();
        int maxd = minr;
        int mind = minr;
        for (int j = 0; j < dir.size(); j++) {
            ct = 0;
            a = x+dir[j][0];
            b = y+dir[j][1];
            if (check(a,b)) {
                // Checks one layer down the num of
                // available moves.
                int deep = 0;
                for (int k = 0; k < dir.size(); k++) {
                    int o1 = a+dir[k][0], o2 = b+dir[k][1];
                    if (check(o1,o2)) {
                        ct++;
                        for (int l = 0; l < dir.size(); l++) {
                            if (check(o1+dir[l][0],o2+dir[l][1])) {
                                deep++;
                            }
                        }
                        mind = min(mind, deep);
                    }
                }
                if (ct < minr) {
                    minr = ct;
                    t1 = a;
                    t2 = b;
                    maxd = deep;
                } else if (ct == minr) {
                    if (mind < maxd) {
                        maxd = mind;
                        t1 = a;
                        t2 = b;
                    }
                }
               
            }
        }
        x = t1;
        y = t2;
    }

    for (int i = 1; i <= SZ; i++) {
        for (int j = 1; j <= SZ; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}





