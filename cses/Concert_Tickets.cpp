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

int n, m;
vector<int> t;
multiset<int> h;

/*

*/

void solve() {
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        t.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        auto it = h.lower_bound(t[i]);
        if (it == h.end() && h.size() > 0) {
            it--;
        } else if (it == h.end()){
            cout << "-1\n";
            continue;
        }

        int price = *it;
        if (price == t[i]) {
            h.erase(it);
        } else if (it == h.begin() && price > t[i]) {
            price = -1;
        } else {
            if (price > t[i]) {
                it--;
            }
            price = *it;
            h.erase(it);
        }

        cout << price << '\n';
    }
}





