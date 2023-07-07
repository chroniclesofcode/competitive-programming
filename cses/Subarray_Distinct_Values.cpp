#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n, k, a[MX];
unordered_map<LL, LL> m;
/*
   1) prefix sums, find two elements which subtract to give x
*/

void solve() {
    cin >> n >> k;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }

    LL distinct = 0;
    LL ans = 0;
    LL j = 0;
    for (LL i = 0; i < n; i++) {
        if (m[a[i]] == 0) {
            distinct++;
        }
        m[a[i]]++;
        while (distinct > k && j < i) {
            m[a[j]]--;
            if (m[a[j]] == 0) distinct--;
            j++;
        }
        ans += i-j+1;
    }
    cout << ans << endl;
}





