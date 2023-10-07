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
const LL MX = 60;
//const LL MOD = 1e7;

int n;
/*
   for every number, we find all sets which include
   this number, and exclude them. Then, just union
   the rest of the sets together using a single for loop.
*/

void solve() {
    cin >> n;
    unordered_set<int> num[MX];
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int elem;
            cin >> elem;
            num[elem].insert(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 50; i++) {
        if (num[i].empty()) continue;
        vector<int> hitlist;
        for (auto it = num[i].begin(); it != num[i].end(); it++) {
            hitlist.push_back(*it);
        }
        int ct = 0;
        for (int j = 1; j <= 50; j++) {
            if (num[j].empty()) continue;
            int hitted = 0;
            for (int k : hitlist) {
                if (num[j].count(k)) {
                    hitted++;
                }
            }
            if (hitted < num[j].size()) ct++;
        }
        ans = max(ans, ct);
    }
    cout << ans << '\n';
}





