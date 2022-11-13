//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
        solve();
}
#define INF numeric_limits<int>::max() / 2
const int MX = 2*1e5 + 5;
int n, q;
int a[MX];
std::vector<int> adj[MX];
std::vector<int> queries;
std::vector<int> ret;

bool used[MX];

ordered_set t[3*MX];

int idx[MX], startRange[MX], endRange[MX];
int totId = 0;

void compute_ranges(int v, int par) {
    if (used[v]) return;
    used[v] = true;
    idx[v] = startRange[v] = totId++;
    for (int nxt : adj[v]) {
        if (nxt == par) continue;
        compute_ranges(nxt, v);
    }
    endRange[v] = totId;
}

void update(int p, int v, int i = 1, int cL = 0, int cR = n) {
    if (cR - cL == 1) {
        t[i].insert(v);
        return;
    }
    int mid = (cL + cR) / 2;
    if (p < mid) update(p, v, i * 2, cL, mid);
    else update(p, v, i * 2 + 1, mid, cR);
    t[i].insert(v);
}

long long query(int qL, int qR, int k, int i = 1, int cL = 0, int cR = n) {
    if (qL == cL && qR == cR) {
        return t[i].order_of_key(k);
    }
    int mid = (cL + cR) / 2;
    long long ans = 0;
    if (qL < mid) ans += query(qL, std::min(qR, mid), k, i * 2, cL, mid);
    if (qR > mid) ans += query(std::max(qL, mid), qR, k, i * 2 + 1, mid, cR);
    return ans;
}

// hi
void debug() {
    cout << endl;
    for (int i = 0; i < 4 * n; i++) {
        std::cout << startRange[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 4 * n; i++) {
        std::cout << endRange[i] << " ";
    }
    std::cout << std::endl;
}

void solve() {
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        std::cin >> u >> v;
        //u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    compute_ranges(0, -1);
    for (int i = 0; i < n; i++) {
        update(idx[i], a[i]);
    }

    //debug();
    //std::cout << query(3, 6, 15) << '\n';
    
    for (int i = 0; i < q; i++) {
        int f, sz;
        std::cin >> f >> sz;
        //std::cout << "POG: " << startRange[f] << " " << endRange[f] << " "  << sz << "\n";
        //std::cout << "answer: \n";
        std::cout << query(startRange[f], endRange[f], sz) << '\n';

        update(idx[f], sz);
    }
    
}



