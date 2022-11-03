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

#define INF numeric_limits<LL>::max() / 2
const LL MX = 600;
LL d[MX][MX];
LL fw[MX][MX];
LL paths[MX][MX];
vector<LL> edges;
LL n, m;

void debug() {
    cout << "FLOYD WARSHALL\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (fw[i][j] == INF) {
                cout << "I ";
            } else {
                cout << fw[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "DIST\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) {
                cout << "I ";
            } else {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "PATHS\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (paths[i][j] == INF) {
                cout << "I ";
            } else {
                cout << paths[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void solve() {
    cin >> n >> m;

    for (LL i = 0; i <= n; i++) {
        for (LL j = 0; j <= n; j++) {
             d[i][j] = INF;
            fw[i][j] = INF;
            if (i == j) {
                //d[i][j] = 0;
                fw[i][j] = 0;
                continue;
            }
        }
    }

    for (LL i = 0; i < m; i++) {
        LL x, y, l;
        cin >> x >> y >> l;
        d[x][y] = l;
        d[y][x] = l;
        fw[x][y] = l;
        fw[y][x] = l;
    }

    for (int i = 1; i <= n; i++) {
        //d[i][i] = 0;
        fw[i][i] = 0;
    }

    // FW
    for (LL k = 1; k <= n; k++) {
        for (LL i = 1; i <= n; i++) {
            for (LL j = 1; j <= n; j++) {
                fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
            }
        }
    }
    // fw is shortest distances
    // d is EDGE distance
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= n; j++) {
            for (LL k = 1; k <= n; k++) {
                // There is a direct path there
                if (d[k][j] < INF && fw[i][k] + d[k][j] == fw[i][j]) {
                    paths[i][j]++;

                }
            }
        }
    }
    //debug();
    for (LL i = 1; i <= n; i++) {
        for (LL j = i+1; j <= n; j++) {
            LL ret = 0;
            for (LL k = 1; k <= n; k++) {
                if (fw[i][k] + fw[k][j] == fw[i][j]) {
                    ret += paths[i][k];
                }
            }
            cout << ret << " ";
        }
    }
    cout << endl;
}






