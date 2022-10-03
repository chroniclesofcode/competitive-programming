#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    LL t;
    cin >> t;
    while (t--) {
        solve();
    }
}


void solve() {
    LL n;
    cin >> n;
    LL l1 = 1;
    LL remain = (n-4);
    LL l2 = remain / 3;
    l2 = l2 == 0 ? 1 : l2;
    LL l3 = remain - l2;
    LL val1 = min(abs(l2 - l1), min(abs(l3 - l2), abs(l3 - l1)));
    l2++;
    l3--;
    if (l2 == 0 || l3 == 0) {
        cout << val1 << '\n';
        return;
    }
    LL val2 = min(abs(l2 - l1), min(abs(l3 - l2), abs(l3 - l1)));

    cout << max(val1, val2) << '\n';
}




