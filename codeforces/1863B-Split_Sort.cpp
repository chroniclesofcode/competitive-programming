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
    vector<int> a(n);
    vector<int> dp(n+1);
    unordered_map<int, int> idx;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
        idx[a[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (idx[i] > idx[i+1]) {
            ans++;
        }
    }
    cout << ans << '\n';

}

/*

*/







