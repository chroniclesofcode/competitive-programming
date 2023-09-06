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
const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL n, k, h[MX];

/*

*/

void solve() {
    cin >> n >> k;
    for (LL i = 0; i < n; i++) {
        cin >> h[i];
    }

    LL c = h[k-1];
    LL l = k-1;
    LL r = k-1;
    if (l == 0 || r == n-1) {
        cout << "YES\n";
        return;
    }
    bool reachable = false;
    LL lmx = k-1;
    LL rmx = k-1;
    LL prevl = -1;
    LL prevr = -1;
    LL slime = h[k-1];
    while (c >= 0) {
        slime = c;
        l = lmx;
        r = rmx;
        
        // No progress made, break out
        if (lmx == prevl && rmx == prevr) {
            break;
        }
        prevl = lmx;
        prevr = rmx;

        while (l > 0 && slime+h[l-1]>=0) {
            l--;
            slime += h[l];
            if (slime >= c) {
                c = slime;
                lmx = l;
            }
        }
        slime = c;
        while (r < n-1 && slime+h[r+1]>=0) {
            r++;
            slime += h[r];
            if (slime >= c) {
                c = slime;
                rmx = r;
            }
        }
        // Made it
        if (l == 0 || r == n-1) {
            reachable = true;
            break;
        }
    }
    if (reachable) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}





