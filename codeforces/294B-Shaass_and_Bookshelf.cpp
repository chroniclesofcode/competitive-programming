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
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;


void solve() {
    cin >> n;
    vector<int> ones, twos;
    for (int i = 0; i < n; i++) {
        int t, w; cin >> t >> w;
        if (t == 1) ones.push_back(w);
        else twos.push_back(w);
    }
    sort(ones.begin(), ones.end());
    sort(twos.begin(), twos.end());
    int osz = ones.size(), tsz = twos.size();
    int tot = osz*1 + tsz*2;
    int ans = tot;
    int p = 0;
    for (int i = 0; i < osz; i++) {
        p += ones[i]; ones[i] = p;
        if (tot - (i+1) >= p) ans = min(ans, tot-(i+1));
    }
    p = 0;
    for (int i = 0; i < tsz; i++) {
        p += twos[i]; twos[i] = p;
        if (tot - (i+1)*2 >= p) ans = min(ans, tot-(i+1)*2);
    }
    for (int i = 0; i < osz; i++) {
        for (int j = 0; j < tsz; j++) {
            int thick = tot - ((i+1)*1 + (j+1)*2);
            int top = ones[i] + twos[j];
            if (thick >= top) ans = min(ans, thick);
        }
    }
    cout << ans << '\n';
}

/*

*/



