#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
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
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;
#define arr array<LL,2>
int n;
/*

*/

void solve() {
    cin >> n;
    vector<arr> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
   
    sort(v.begin(), v.end(), greater<arr>());
    LL prev = -1;
    int ct = 0;
    LL ans = 0;
    for (auto e : v) {
        if (e[0] == prev && ct == prev) continue;
        if (e[0] != prev) {
            prev = e[0];
            ct = 0;
        }
        ans += e[1];
        ct++;
        prev = e[0];
    }
    cout << ans << '\n';
}





