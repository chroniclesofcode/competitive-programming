#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

vector<int> l;
MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

    int p = 0;
    l.push_back(0); l.push_back(0);
    for (int i = 1; i <= 100; i++) {
        p += i;
        l.push_back(p);
    }

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

void solve() {
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        int a = i, b = n-i;
        a = a*(a-1)/2; b = b*(b-1)/2;
        if (a + b == k) {
            cout << "YES\n";
            int one = i, two = n-i;
            while (one--) cout << 1 << ' ';
            while (two--) cout << -1 << ' ';
            cout << '\n'; return;
        }
    }
    cout << "NO\n";
}

/*

*/







