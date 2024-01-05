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
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0]*2 >= a[n-1]) {
        fout << 0 << '\n';
        return;
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a.begin(), a.end(), a[i]*2);
        if (it == a.begin()) continue;
        it--;
        if (*it <= a[i]*2) {
            ans = min(ans, (n-1)-(int)(it-a.begin())+i);
        }
    }
    fout << ans << '\n';
}

/*

*/



