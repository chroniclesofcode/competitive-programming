#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();


MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    LL t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {  
    LL n, c;
    cin >> n >> c;
    LL a;
    unordered_map<LL, LL> m;
    for (LL i = 0; i < n; i++) {
        cin >> a;
        m[a]++;
    }
    // For each orbit, determine how many planets there
    // are. Cost of destruction of orbit is min(c, num_planets).
    LL ret = 0;
    for (auto it : m) {
        ret += min(it.second, c);
    }

    cout << ret << '\n';
}






