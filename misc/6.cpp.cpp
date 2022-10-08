#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

const int MX = 1e5 + 100;
vector<int> a(MX);
vector<int> x(MX);
vector<int> t;

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) cin >> x[i];

    t.reserve(MX);
    t.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) {
            t.push_back(a[i]);
        }
    }


    for (int i = 0; i < q; i++) {
        auto it = upper_bound(t.begin(), t.begin() + t.size(), x[i]);
        int idx = it - t.begin();
        cout << t.size() - idx << '\n';
    }
}

