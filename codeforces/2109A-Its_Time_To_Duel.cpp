#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
    }
    if (n == 2) {
        if (a[0] + a[1] == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        return;
    }
    int has_zero = a[0] == 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == 0 && a[i-1] == 0) {
            cout << "YES\n";
            return;
        }
        if (a[i] == 0) {
            has_zero = 1;
        }
    }
    if (!has_zero) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

/*

*/