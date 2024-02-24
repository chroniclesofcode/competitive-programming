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
    string s, t;
    cin >> t; cin >> s;
    if (s.size() < t.size()) swap(s, t);
    n = s.size(); m = t.size();
    int ans = 0;
    if (n == m) {
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (diff) {
                ans += 9;
            }
            if (s[i] != t[i]) {
                if (diff == 0)
                    ans += abs(s[i]-t[i]);
                diff = 1;
            }
        }
    } else {
        ans = s[0]-'0';
        for (int i = 1; i < n; i++) {
            ans += 9;
        }
    }
    cout << ans << '\n';
}
// 99 1900







 
