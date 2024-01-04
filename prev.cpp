#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 1 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

int lft[MX], rgt[MX];

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    int ans = 1;
    lft[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) lft[i] = lft[i-1]+1;
        else lft[i] = 1;
    }
    rgt[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] < a[i+1]) rgt[i] = rgt[i+1]+1;
        else rgt[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        int tot1 = 1, tot2 = 1, tot3 = 1;
        // note it's a[i+1]-1 so that the middle element
        // is not the same! (strictly greater).
        if (i > 0 && i < n-1 && a[i-1] < a[i+1]-1) {
            tot1 += lft[i-1] + rgt[i+1];
        }
        if (i != n-1) {
            tot2 += rgt[i+1];
        }
        if (i != 0) {
            tot3 += lft[i-1];
        }
        ans = max({ans, tot1, tot2, tot3});
    }
    cout << ans << '\n';
}

/*
   calculate two prefix arrays, one lft to rgt, how
   many strictly increasing elements up to i.
   Also, rgt to lft how many strictly decreasing down
   to j.
   For each element, treat it as if it was the non-valid
   element and check if lft and rgt are strictly 
   increasing and calculate the running max.
*/



