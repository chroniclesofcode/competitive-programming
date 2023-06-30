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

int x, n, p[MX];
#define arr array<int,2>
set<arr> intervals;
multiset<int> lengths;
/*

*/

void reml(int sz) {
    sz++;
    auto it = lengths.find(sz);
    if (it != lengths.end()) {
        lengths.erase(it);
    }
}

void addl(int sz) {
    sz++;
    if (sz > 0)
        lengths.insert(sz);
}

void addi(int u, int v) {
    if (v - u < 0) return;
    intervals.insert({u,v});
    addl(v-u);
}

void solve() {
    cin >> x >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        //tmp--;
        p[i] = tmp;
    }
    intervals.insert({0,x-1});
    lengths.insert(x);
    for (int i = 0; i < n; i++) {
        if (intervals.size() == 0) {
            cout << 0 << ' ';
            continue;
        }
        if (p[i] == 0 || p[i] == x) {
            auto it = lengths.end();
            it--;
            cout << *it << ' ';
            continue;
        }
        auto it = intervals.lower_bound({p[i],p[i]});
        it--;
        auto v = *it;
        intervals.erase(it);
        reml(v[1]-v[0]);

        addi(v[0], p[i]-1);
        addi(p[i], v[1]);
        if (lengths.size() == 0) {
            cout << 0 << ' ';
        } else {
            auto it = lengths.end();
            it--;
            cout << *it << ' ';

        }
    }
    cout << endl;
    
}





