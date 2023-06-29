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

LL n, m, a[MX], pos[MX];

/*

*/

void solve() {
    cin >> n >> m;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    LL ans = 1;
    pos[n+1] = MX-1;
    for (LL i = 1; i <= n; i++) {
        if (a[i] < n && pos[a[i]+1] < i) {
            ans++;
        }
    }
    LL x, y;
    // we have to look at x-1, y-1 to get a better
    // understanding how ans moves
    for (LL i = 0; i < m; i++) {
        cin >> x >> y;
        if (x > y) swap(x,y);

        int xbefore = pos[a[x]-1];
        int xafter = pos[a[x]+1];
        int xfuture = y;

        int ybefore = pos[a[y]-1];
        int yafter = pos[a[y]+1];
        int yfuture = x;
        /*

           xbefore = 3;
           xafter = 5;
           xfuture = 3
           x = 2

           ybefore = 0
           yafter = 2
           yfuture = 2
           y = 3
           */
        if (xbefore > x && xbefore <= xfuture) {
            ans--;
        } 
        if (xbefore < x && xbefore > xfuture) {
            ans++;
        }
        if (xafter < x && xafter > xfuture) {
            ans--;
        }
        if (xafter > x && xafter <= xfuture) {
            ans++;
        }


        if (ybefore > y && ybefore <= yfuture) {
            ans--;
        }
        if (ybefore < y && ybefore > yfuture) {
            ans++;
        }
        if (yafter < y && yafter > yfuture) {
            ans--;
        }
        if (yafter > y && yafter <= yfuture) {
            ans++;
        }

        cout << ans << '\n';
        swap(pos[a[x]], pos[a[y]]);
        swap(a[x],a[y]);
    }

}





