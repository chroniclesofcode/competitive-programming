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

int n;
int a[MX];
unordered_map<int, int> m;
/*

*/

void solve() {
    m.reserve(1024);
    m.max_load_factor(0.25);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int seq = 0;
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (m[a[i]] == 0) {
            //cout << "u: " << i << " " << a[i] << endl;
            m[a[i]] = i;
            seq++;
        } else if (m[a[i]] > 0) {
            //cout << "nu: " << i << " " << a[i] << endl;
            // I made a very very careless mistake here
            // int idx = m[a[i]]+1;
            // This means I will update the array at the LAST
            // occurence of the element seen, even if it was
            // 10 light years ago and the back of the array
            // already progressed from there. This makes the
            // answers I return extremely big.

            idx = max(m[a[i]]+1, idx);
            m[a[i]] = i;
            seq = i - idx + 1;
        }
        ans = max(ans, seq);
    }
    cout << ans << endl;
}





