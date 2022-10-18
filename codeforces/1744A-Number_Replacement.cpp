#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) 
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 1e4;
unordered_map<int, char> m;
int a[MX];

void solve() {
    int n;
    cin >> n;
    m.clear();

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (!m[a[i]]) {
            m[a[i]] = s[i];
        } else if (m[a[i]] != s[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

