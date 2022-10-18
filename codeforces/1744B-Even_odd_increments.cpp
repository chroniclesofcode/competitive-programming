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
    while (t--) 
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 1e6;
LL a[MX];

void solve() {
    LL n, q;
    cin >> n >> q;
    LL odd = 0, even = 0;
    LL sum = 0;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        sum += a[i];
    }
    LL type, x;
    for (LL i = 0; i < q; i++) {
        cin >> type >> x;
        if (type == 0) {
            sum += even * x;
            if (x % 2 != 0) {
                odd += even;
                even = 0;
            }
        } else if (type == 1) {
            sum += odd * x;
            if (x % 2 != 0) {
                even += odd;
                odd = 0;
            }
        }
        cout << sum << '\n';
    }
}

