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

const LL MX = 5 * 1e3;
//const LL MOD = 1e7;

LL n, dist[MX][MX], p;

/*

*/

void solve() {
    cin >> n;
    LL x;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            cin >> x;
            dist[i][j] = x;
        }
    }
    cin >> p;
    LL y, z;
    for (LL g = 0; g < p; g++) {
        cin >> x >> y >> z;
        x--; y--;
        dist[x][y] = min(dist[x][y], z);
        dist[y][x] = dist[x][y];
        LL ans = 0;
        for (LL i = 0; i < n; i++) {
            for (LL j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][x]+z+dist[y][j]);
                dist[i][j] = min(dist[i][j], dist[i][y]+z+dist[x][j]);
            }
        }
        for (LL i = 0; i < n; i++) {
            for (LL j = 0; j < i; j++) {
                ans += dist[i][j];
            }
        }

        cout << ans << ' ';
    }
    cout << endl;

    

}





