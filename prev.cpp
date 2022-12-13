#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 10;
//const LL MOD = 1e7;

int n, m;
int b[MX][MX];
int r[MX];
int c[MX];
/*

*/

vector<pair<int, int>> rooks;

void solve() {
    memset(b, 0, sizeof b);
    memset(r, 0, sizeof r);
    memset(c, 0, sizeof c);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        b[x][y] = 1;
        r[x]++;
        c[y]++;
        rooks.push_back({x, y});
    }
    bool res = false;

    for (auto p : rooks) {
        int x = p.first;
        int y = p.second;
        r[x]--;
        c[y]--;
        b[x][y] = 0;
        for (int i = 0; i < n; i++) {
            if (res) break;
            for (int j = 0; j < n; j++) {
                if (r[i] == 0 && c[i] == 0 && i != x && j != y && !b[x][y]) {
                    res = true;
                }
            }
        }
        if (res) break;
        r[x]++;
        c[y]++;
        b[x][y] = 1;
    }

    if (res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}





