#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {  
    int n, k;
    cin >> n >> k;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        int v = i % k;
        m[v] = max(m[v], a[i]);
    }
    LL ans = 0;
    for (int i = 0; i < k; i++) {
        ans += m[i];
    }
    cout << ans << '\n';
    
}

