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
#define arr array<LL,2>
LL n, k;
vector<arr> a;
multiset<arr> s;
/*
 
*/
 
void solve() {
    cin >> n >> k;
    LL x,y;
    for (LL i = 0; i < n; i++) {
        cin >> x >> y;
        a.push_back({y, x});
    }
    sort(a.begin(), a.end());
    LL movies = 0;
    for (auto &[fin, beg] : a) {
        if (s.size() == 0) {
            s.insert({fin,0});
            movies++;
            continue;
        }
        auto it = s.upper_bound({beg, INF});
        if (it != s.begin()) it--;
        LL tmp = (*it)[1];
        if ((*it)[0] <= beg) {
            s.erase(it);
            s.insert({fin,tmp});
            movies++;
        } else if (s.size() < k) {
            s.insert({fin,(LL)s.size()});
            movies++;
        }

    }
    cout << movies << endl;
}
 
 
