#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;


void solve() {
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> m;
        a.push_back(m);
        b.push_back(m);
    }
    reverse(b.begin(), b.end());
    vector<int> res;
    if (std::is_sorted(a.begin(), a.end())) {
        cout << 0 << '\n';
        return;
    } else if (std::is_sorted(a.begin(), a.end(), greater<int>())) {
        cout << 1 << '\n';
        return;
    }
    // for a
    int i = 1;
    for (; i < n && a[i] >= a[i-1]; i++);
    auto it = a.begin() + i;
    if (a[n-1] <= a[0] && std::is_sorted(a.begin(), it) && std::is_sorted(it, a.end())) {
        res.push_back(n-i);
    }
    i = 1;
    for (; i < n && a[i-1] >= a[i]; i++);
    it = a.begin() + i;
    if (a[n-1] >= a[0] && std::is_sorted(a.begin(), it, greater<int>()) && std::is_sorted(it, a.end(), greater<int>())) {
        res.push_back(n-i+1);
    }
    // for b
    i = 1;
    for (; i < n && b[i] >= b[i-1]; i++);
    it = b.begin() + i;
    if (b[n-1] <= b[0] && std::is_sorted(b.begin(), it) && std::is_sorted(it, b.end())) {
        res.push_back(n-i+1);
    }
    i = 1;
    for (; i < n && b[i-1] >= b[i]; i++);
    it = b.begin() + i;
    if (b[n-1] >= b[0] && std::is_sorted(b.begin(), it, greater<int>()) && std::is_sorted(it, b.end(), greater<int>())) {
        res.push_back(n-i+1+1);
    }

    if (res.size()) {
        cout << *min_element(res.begin(), res.end()) << '\n';
    } else {
        cout << -1 << '\n';
    }
}

/*

*/



