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
int dp[101][101];

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    vector<int> a(n*m);
    for (int i = 0; i < n*m; i++) cin >> a[i];
    int small = min(n,m);
    int big = max(n,m);
    sort(a.begin(), a.end());
    // where big is in corner
    int maxdiff = *a.rbegin() - *a.begin();
    auto it = a.begin(); it++;
    int second = *a.rbegin() - *it;
    int ans = 0;
    ans += maxdiff * ((big-1)*small);
    ans += second * (small-1);

    // where small is in corner
    int ans2 = 0;
    auto it2 = a.rbegin(); it2++;
    second = *it2 - *a.begin();
    ans2 += maxdiff * ((big-1)*small);
    ans2 += second * (small-1);
    cout << max(ans, ans2) << '\n';
}

/*

*/







