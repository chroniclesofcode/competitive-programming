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

int n, x;
vector<int> p;
int vis[MX];
/*

*/

void solve() {
    cin >> n >> x;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        p.push_back(a);
    }
    sort(p.begin(), p.end(), greater<int>());
    int j = n-1;
    int ans = 0;
    for (int i = 0; i < n && i <= j; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        int rem = x - p[i];
        if (p[j] <= rem && !vis[j]) {
            vis[j] = 1;
            j--;
        }
        ans++;
    }
    cout << ans << endl;
}





