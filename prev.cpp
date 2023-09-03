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

int a, b, c;

/*

*/

/*
   k1 k2 k3
   k2 k1 k3
   k1 k3 k2
   k2 k3 k1
   k3 k2 k1
   k3 k1 k2
   */


void solve() {
    cin >> a >> b >> c;
    if (a == 1 || b == 1 || c == 1) {
        cout << "YES\n";
        return;
    }
    if (a == 3 && b == 3 && c == 3) {
        cout << "YES\n";
        return;
    }
    int ct2 = 0;
    if (a == 2) ct2++;
    if (b == 2) ct2++;
    if (c == 2) ct2++;
    if (ct2 >= 2) {
        cout << "YES\n";
        return;
    }
    int ct4 = 0;
    if (a == 4) ct4++;
    if (b == 4) ct4++;
    if (c == 4) ct4++;
    if (ct4 == 2 && ct2 == 1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}





