#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
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
const LL MX = 101;
//const LL MOD = 1e7;

int n, k, a[MX];

/*

*/

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int distinct = 0;
    int unsorted = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) {
            distinct = 1;
        }
        if (a[i] < a[i-1]) unsorted = 1;
    }
    if (k <= 1 && distinct && unsorted) cout << "NO\n";
    else cout << "YES\n";
}





