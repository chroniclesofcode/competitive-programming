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
constexpr int NINF = -INF;
constexpr int MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

void solve() {
    cin >> n;
    string s, t;
    cin >> s >> t;
    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) diff++;
    }
    if (diff == 0) {
        cout << 0 << '\n'; return;
    }
    int diff_rev = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) diff_rev++;
    }
    if (diff_rev == 0) {
        cout << 2 << '\n'; return;
    }
    int orig = diff;
    if (diff % 2 == 0) {
        diff *= 2;
    } else {
        diff = (diff-1)*2 + 1;
    }
    if (orig == n) {
        diff = min(diff, orig*2-1);
    }
    orig = diff_rev;
    if (diff_rev % 2 == 0) {
        diff_rev *= 2;
        diff_rev--;
    } else {
        diff_rev = diff_rev*2;
    }
    if (orig == n) {
        diff_rev = min(diff_rev, orig*2-1);
    }
    
    cout << min(diff, diff_rev) << '\n';
}

/*

*/
