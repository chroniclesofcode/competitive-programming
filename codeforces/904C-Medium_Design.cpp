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
#define arr array<LL,2>
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;
 
LL n, m;
 
/*
 
*/
 
void solve() {
    #define arr array<LL,2>
    cin >> n >> m;
    map<LL, LL> seg;
    vector<arr> a;
    for (LL i = 0; i < n; i++) {
        LL l, r;
        cin >> l >> r;
        l--; r--;
        a.push_back({l, r});
        seg[l]++;
        seg[r+1]--; // watch out, always +1
    }
    LL p = 0;
    LL b = 0, bidx = 0;
    for (auto it = seg.begin(); it != seg.end(); it++) {
        if (it->first >= m) break;
        p += it->second;
        if (p > b) {
            b = p;
            bidx = it->first;
        }
    }
    map<LL, LL> seg2;
    for (LL i = 0; i < a.size(); i++) {
        if (bidx >= a[i][0] && bidx <= a[i][1]) {
            seg2[a[i][0]]++;
            seg2[a[i][1]+1]--;
        }
    }
    p = 0;
    LL ans = b;
    auto it = seg2.begin();
    if (it->first > 0) {
        cout << b << '\n';
        return;
    }
    for (auto it = seg2.begin(); it != seg2.end(); it++) {
        if (it->first >= m) {
            break;
        }
        p += it->second;
        ans = min(ans, p);
    }
    cout << b - ans << '\n';
}
