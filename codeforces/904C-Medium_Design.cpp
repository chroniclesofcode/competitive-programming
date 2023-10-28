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
    map<LL, LL> seg2;
    for (LL i = 0; i < n; i++) {
        LL l, r;
        cin >> l >> r;
        l--; r--;
        if (l != 0) {
            seg[l]++; seg[r+1]--; // always r+1
        }
        if (r != m-1) {
            seg2[l]++; seg2[r+1]--;
        }
    }
    LL b = 0;
    LL p = 0;
    for (auto it : seg) {
        p += it.second;
        b = max(b, p);
    }
    p = 0;
    for (auto it : seg2) {
        p += it.second;
        b = max(b, p);
    }
    cout << b << '\n';
}
