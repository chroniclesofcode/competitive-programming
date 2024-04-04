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

int n, m, k;

int a[2][MX];

void solve() {
    cin >> n;
    int ct = 1;
    for (int i = 0; i < n-1; i += 2) {
        a[1][i] = ct++;
        a[0][i+1] = ct++;
    }
    for (int i = 1; i < n-1; i += 2) {
        a[1][i] = ct++;
        a[0][i+1] = ct++;
    }

    a[1][n-1] = ct++;
    a[0][0] = ct++;

    for (int i = 0; i < n; i++) cout << a[0][i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << a[1][i] << ' ';
    cout << '\n';
}

/*

*/







