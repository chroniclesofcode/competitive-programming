#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
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
    cin >> n; // num courses
    // min, max for each course
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
    }
    cin >> q; // num students
    // range l,r courses available for ith student
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
    }
}

/*

*/







