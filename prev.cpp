#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> mark(n+2);
    for (auto e : a) mark[e] = 1;
    int mex = 0;
    for (int i = 0; i <= n+1; i++) {
        if (!mark[i]) {
            mex = i;
            break;
        }
    }
    if (mex == 0) {
        cout << "2\n1 1\n2 " << n << '\n';
        return;
    }
    vector<pair<int,int>> ans;
    fill(mark.begin(), mark.end(), 0);
    int j = 0;
    for (int i = 0; i < n; i++) {
        mark[a[i]] = 1;
        while (j <= n+1 && mark[j] && mark[j+1] == 1) {
            j++;
        }
        if (i == n-1) {
            cout << -1 << '\n'; return;
        }
        if (mark[j] && j == mex-1) {
            ans.push_back({1,i+1});
            fill(mark.begin(), mark.end(), 0);
            for (int k = i+1; k < n; k++) {
                mark[a[k]] = 1;
            }
            for (int k = 0; k < mex; k++) {
                if (!mark[k]) {
                    cout << -1 << '\n'; return;
                }
            }
            ans.push_back({i+2, n});
            break;
        }
    }

    cout << ans.size() << '\n';
    for (auto &p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

/*
   there can only be 1 mex that is valid : the
   smallest number that doesn't exist. We then
   seek to divide up the array properly. Any 
   larger number will not be the mex since it
   will face the smallest mex as a 'barrier'.
*/







