#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

        solve();
}
#define INF numeric_limits<LL>::max()
const LL MX = 501;
LL d[MX][MX];
LL adj[MX][MX];
LL x[MX];
bool used[MX];

// Very interesting question
/*
    It very clearly seems to be a floyd warshall
    question because we are trying to find all pairs
    shortest path. The LLeresting thing is, in normal
    floyd warshall it is 0..k LLermediary nodes for each
    i, j. In this case, we can't really just take some m in 
    0..m..k and remove it because that makes no sense at all.
    Everything depends on the values before it

    So instead, we go backwards from our input (see problem
    ancient berland roads), and start from 0 nodes available.
    Then we build the graph from scratch, every iteration
    of floyd warshall we set the new node to be the LLermediary node.
    We then add all of its children in and do the calculations.
    We also use a 'used' array to note which have been added in
    and only calculate the total from it. I did have a small bug
    where I didn't add the total if any of the nodes were not used,
    but u should actually calculate the total anyways regardless if
    it is used or not.
*/

void solve() {
    LL n;
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    for (LL i = 1; i <=n; i++) {
        cin >> x[i];
    }
    vector<LL> res;
    res.reserve(n);
    LL total = 0;
    for (LL end = n; end >= 1; end--) {
        LL k = x[end];
        used[k] = true;
        for (LL i = 1; i <= n; i++) {
            adj[k][i] = d[k][i];
        }
        total = 0;
        for (LL i = 1; i <= n; i++) {
            for (LL j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
                if (used[i] && used[j]) {
                    total += d[i][j];
                }
            }
        }
        res.push_back(total);
    }
    for (auto it = res.rbegin(); it != res.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


