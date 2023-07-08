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

void debug() {
    cout << "movies\n";
    for (arr e : s) {
        cout << e[0] << ' ' << e[1] << endl;
    }
    cout << endl;
}

void solve() {
    cin >> n >> k;
    LL x,y;
    for (LL i = 0; i < n; i++) {
        cin >> x >> y;
        a.push_back({y, x});
    }
    sort(a.begin(), a.end());
    //debug();
    LL movies = 0;
    for (LL i = 0; i < k; i++) {
        s.insert({0,i});
    }
    for (auto &[fin, beg] : a) {
        auto it = s.upper_bound({beg, INF});
        if (it == s.begin()) continue;
        it--;
        LL tmp = (*it)[1];
        s.erase(it);
        s.insert({fin, tmp});
        movies++;
    }
    cout << movies << endl;
}





