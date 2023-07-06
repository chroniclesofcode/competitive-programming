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

int n, a[MX], res[MX];
stack<array<int,2>> s;
/*

*/

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    res[0] = 0;
    s.push({a[0],1});
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            res[i] = 0;
        } else {
            while (!s.empty() && s.top()[0] >= a[i]) s.pop();
            if (!s.empty()) {
                res[i] = s.top()[1];
            }
        }
        s.push({a[i], i+1});
    }
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << endl;
}





