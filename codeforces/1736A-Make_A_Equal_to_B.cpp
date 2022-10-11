#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
        solve();
}

const int MX = 1e3;
int a[MX];
int b[MX];

void solve() {
    int n;
    cin >> n;
    int a1 = 0, b1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            a1++;
        }
    }
    int equal = 0;
    int sameloc = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == 1) {
            b1++;
            if (b[i] == a[i]) {
                sameloc++;
            }
        }
        if (b[i] == a[i])
            equal++;
    }
    if (equal == n) {
        cout << 0;
    } else if (b1 == a1) {
        cout << 1;
    } else if (b1 > a1) {
        if (sameloc == a1) {
            cout << b1 - a1;
        } else {
            cout << 1 + b1 - a1;
        }
    } else {
        if (sameloc == b1) {
            cout << a1 - b1;
        } else {
            cout << 1 + a1 - b1;
        }
    }
    cout << '\n';
}

