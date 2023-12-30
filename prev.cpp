#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<LL,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;


void solve() {
    cin >> n >> k;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<LL> pref;
    LL p = 0;
    for (LL i = 0; i < n; i++) {
        p += a[i];
        pref.push_back(p);
    }
    LL ans = 1;
    LL ret = a[0];
    LL j = 0;
    LL sum = 0;
    for (LL i = 0; i < n; i++) {
        while (j < i && a[i]*(i-j+1) - (pref[i]- (j == 0 ? 0 : pref[j-1])) > k) {
            j++;
        }
        if (i-j+1 > ans) {
            ans = i-j+1;
            ret = a[i];
        }
    }
    cout << ans << ' ' << ret << '\n';
}

/*

*/



