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

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

const int MX = 1e5 + 100;
int a[MX];
int b[MX];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    b[0] = a[0];
    b[n] = a[n-1];
    for (int i = 1; i < n; i++) {
        b[i] = lcm(a[i], a[i-1]);
    }
    for (int i = 0; i < n; i++) {
        if (gcd(b[i], b[i+1]) != a[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

