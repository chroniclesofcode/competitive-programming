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

LL n;
vector<LL> a;
set<LL> s;
/*

*/

void solve() {
    cin >> n;
    LL x;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    LL ans = 1;
    s.insert(a[0]);
    // For every element, search the set
    // to see if we can find an element under
    // it - if so, we remove it, then add
    // this new one in.
    for (LL i = 1; i < n; i++) {
        auto it = s.lower_bound(a[i]);
        if (it == s.begin()) {
            ans++;
            s.insert(a[i]);
            continue;
        } 
        it--;
        if (*it + 1 == a[i]) {
            s.erase(it);
            s.insert(a[i]);
        } else {
            ans++;
            s.insert(a[i]);
        }
    }
    cout << ans << endl;
}





