#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 2 * 1e5 + 1;
//const LL MOD = 1e7;

int n;
vector<bool> used(MX);

/*

*/

void solve() {
    cin >> n;
    vector<int> v;
    used.assign(n*2, false);
    for (int i = 1; i <= n; i++) {
        int sz = v.size();
        if (used[i]) {
            continue;
        } else {
            v.push_back(i);
            used[i] = true;
        }
        while (i > 1 && v[v.size()-1]*2 <= n) {
            used[v[v.size()-1]*2] = true;
            v.push_back(v[v.size()-1]*2);
        }
    }
    for (auto c : v) {
        cout << c << ' ';
    }
    cout << '\n';
}





