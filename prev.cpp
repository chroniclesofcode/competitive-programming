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
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

void solve() {
    cin >> n;
    vector<int> isp(n+1, 1);
    vector<int> tmp;
    isp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isp[i]) {
            tmp.push_back(i);
            if ((LL)i*i <= n) {
                for (int j = i*i; j <= n; j += i) {
                    isp[j] = false;
                }
            }
        }
    }
    
    vector<int> ans;
    reverse(tmp.begin(), tmp.end());
    for (auto t : tmp) {
        ans.push_back(t);
    }
    for (int i = 1; i <= n; i++) {
        if (!isp[i]) {
            ans.push_back(i);
        }
    }
    for (auto a : ans) {
        cout << a << ' ';
    }
    cout << '\n';
}

/*

*/







