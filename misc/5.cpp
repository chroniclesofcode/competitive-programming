#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<pair<LL, LL>> team(n);
    for (LL i = 0; i < n; i++) {
        LL p, t;
        cin >> p >> t;
        //if (t > m) t == m;
        team[i] = make_pair(p, t);
    }
    sort(team.begin(), team.end(), greater<pair<LL,LL>>());

    LL ret = 0;
    LL curr = m;
    LL i = 0;
    LL rm;
    while (i < team.size() && k > 0) {
        rm = min(team[i].second, curr);
        team[i].second -= rm;
        curr -= rm;
        ret += rm * team[i].first;
        if (team[i].second == 0) {
            i++;
        }
        if (curr == 0) {
            k--;
            curr = m;
        }
    }

    cout << ret << '\n';
}
   
