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

#define INF numeric_limits<LL>::max() / 2
const int MX = 3 * 1e5;
int a[MX];

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

// This was actually surprisingly not that easy because of
// the time constraints. I had to compress and remove all the
// duplicates whilst keeping track of the highest indices
// Then run O(n^2) for n <= 1000 instead of 10^5.

void solve() {
    unordered_map<int, int> m;
    int n;
    cin >> n;
    int tmp;
    int count = 1;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (!m[tmp]) {
            a[count] = tmp;
            count++;
        }
        m[tmp] = i;
    }
    int ret = -1;
    for (int i = 1; i < count; i++) {
        for (int j = i; j < count; j++) {
            if (gcd(a[i], a[j]) == 1) {
                ret = max(ret, m[a[i]]+m[a[j]]);
            }
        }
    }
    cout << ret << '\n';
}

