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

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 4002;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

int dp[MX][MX];
vector<int> id = vector<int>((int)1e6+3, 0);
void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ct = 1;
    for (int i = 0; i < n; i++) {
        if (id[a[i]] == 0) id[a[i]] = ct++;
    }
    for (int i = 0; i < n; i++) {
        a[i] = id[a[i]];
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (dp[j][a[i]] == 0) {
                dp[i][a[j]] = max(dp[i][a[j]], 2);
            } else {
                dp[i][a[j]] = max(dp[i][a[j]], dp[j][a[i]] + 1);
            }
            ans = max(ans, dp[i][a[j]]);
        }
    }
    cout << ans << '\n';
}

/*

*/



