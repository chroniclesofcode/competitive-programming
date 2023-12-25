#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

void solve() {
    cin >> n;
    int up = 0, down = 0, left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > 0) {
            right = 1;
        } else if (x < 0) {
            left = 1;
        }
        if (y > 0) {
            up = 1;
        } else if (y < 0) {
            down = 1;
        }
    }
    if (up && down && left && right) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

/*

*/







