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

LL n, x;
vector<array<LL,2>> a;
//unordered_map<LL, LL> m;
/*

*/

void solve() {
    cin >> n >> x;
    LL u;
    for (LL i = 0; i < n; i++) {
        cin >> u;
        a.push_back({u, i});
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while (l < r) {
            LL val = a[l][0]+a[r][0]+a[i][0];
            if (val < x) l++;
            else if (val > x) r--;
            else if (a[i][1] != a[l][1] && a[i][1] != a[r][1] && a[l][1] != a[r][1]) {
                cout << a[l][1]+1 << ' ' << a[r][1]+1 << ' ' << a[i][1]+1 << endl;
                return;
            } else {
                l++;
            }
        }
    }


    cout << "IMPOSSIBLE\n";
}





