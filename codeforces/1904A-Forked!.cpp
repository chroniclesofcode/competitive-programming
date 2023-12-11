#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

int n;
vector<vector<int>> dirs = {{1,1},{-1,1},{1,-1},{-1,-1}};

void solve() {
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    int ans = 0;
    vector<array<int,2>> v;
    for (auto d : dirs) {
        int nx = xk + a*d[0], ny = yk + b*d[1];
        int hx = xk + b*d[0], hy = yk + a*d[1];
        v.push_back({nx,ny});
        if (hx != nx && hy != ny)
            v.push_back({hx,hy});
        
    }
    for (auto e : v) {
        int nx = e[0], ny = e[1];
        for (auto g : dirs) {
            if (nx + a*g[0] == xq && ny + b*g[1] == yq) {
                ans++;
                break;
            }
            if (nx + b*g[0] == xq && ny + a*g[1] == yq) {
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
}





