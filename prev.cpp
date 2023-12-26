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
    vector<LL> w(n);
    vector<LL> idx(n);
    for (LL i = 0; i < n; i++) cin >> a[i];
    LL sum = 0, ans = 0;
    LL first = 0, second = 0;
    for (LL i = 0; i < n; i++) {
        sum += a[i];
        if (i >= k) {
            sum -= a[i-k];
        }
        if (i >= k-1) {
            if (sum > ans) {
                ans = sum;
                first = i-(k-1);
            }
            w[i] = ans;
            idx[i] = first;
        }
    }
    LL ret = 0;
    sum = 0;
    LL r1 = 0, r2 = 0;
    for (LL i = 0; i < n; i++) {
        sum += a[i];
        if (i >= k) {
            sum -= a[i-k];
        }
        if (i >= 2*k-1) {
            if (sum + w[i-k] > ret) {
                ret = sum + w[i-k];
                r1 = idx[i-k];
                r2 = i-k+1;
            }
        }
    }

    cout << r1+1 << ' ' << r2+1 << '\n';
}

/*

*/



