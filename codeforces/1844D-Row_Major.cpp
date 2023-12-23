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
    vector<int> fact;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) fact.push_back(i);
    }
    vector<int> ans(n);
    int ch[26];
    for (int i = 0; i < n; i++) {
        memset(ch, 0, sizeof(ch));
        for (auto j : fact) {
            if (i - j < 0) break;
            ch[ans[i-j]] = 1;
        }
        for (int j = 0; j < 26; j++) {
            if (!ch[j]) {
                ans[i] = j;
                break;
            }
        }
    }
    for (auto a : ans) {
        cout << (char)(a+'a');
    }
    cout << '\n';
}

/*
   if it's odd, just alternate abababab, you cannot have a grid
   with odd.
   if it's even, 
   6%1 == 0, so every 1 in front must not be the same
   6%2 == 0, so every 2 in front must not be the same
   6%3 == 0, so every 3 in front must not be the same
   6%4 != 0, so it is OK to be the same as 4
   same with 5.
*/







