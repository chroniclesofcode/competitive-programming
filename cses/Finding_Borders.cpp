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

int n, m, pi[MX], occ[MX];
string t, s;

/*

*/

void prefix_f() {
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
}

void debug() {
    cout << "prefix: ";
    for (int i = 0; i < n; i++) {
        cout << pi[i] << ' ';
    }
    cout << endl;
}

void solve() {
    cin >> s;
    n = s.length();

    vector<int> ans;
    prefix_f();
    //debug();
    int v = n-1;
    while (v > 0) {
        v = pi[v];
        if (v > 0) ans.push_back(v);
        v--;
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << ' ';
    cout << endl;
}





