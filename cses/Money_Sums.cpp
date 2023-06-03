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
const LL MX = 110;
//const LL MOD = 1e7;

int n;
int a[MX];
set<int> s;
set<int> tmp;
vector<int> v(100000);
/*

*/

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        v.clear();
        for (auto j = s.begin(); j != s.end(); j++) {
            v.push_back(*j + a[i]);
        }
        s.insert(a[i]);
        for (int j = 0; j < v.size(); j++) {
            s.insert(v[j]);
        }
    }
    cout << s.size() << '\n';
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << '\n';
}





