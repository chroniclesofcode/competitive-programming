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

int n;
list<int> l;
/*

*/

void solve() {
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }
    auto it = l.begin();
    auto en = l.end();
    it++;
    while (l.size()) {
        cout << *it << ' ';
        auto tmp = it;
        it++;
        l.erase(tmp);
        if (it == en) {
            it = l.begin();
        }
        if (l.size()) it++;
        if (it == en && l.size()) {
            it = l.begin();
        }
    }
    cout << endl;
}





