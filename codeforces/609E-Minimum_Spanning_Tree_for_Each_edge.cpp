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

// Find MST
// if it's already there, then it's the MST sum
// if it's not, then add the edge anyways
// this will ALWAYS cause a cycle to occur
// We can remove any edge of this cycle and
// it will still be a tree, and since it was
// originally a tree, only one edge will have to
// be removed - this will be the one with the
// greatest weight. To find it... we will traverse
// the cycle upwards until they reach each other
// Probably binary lift cuz its similar to LCA and time 
// complexity wont allow v^2 solutions probs

struct Edge {
    LL u, v, w, idx;
    
    bool operator<(const Edge &o) const {
        return w < o.w;
    }
};

#define INF numeric_limits<LL>::max() / 2
const LL MX = 2 * 1e5 + 10;
const LL LOG = 19;
vector<pair<LL, LL>> adj[MX];

vector<LL> group;
vector<LL> sze;
vector<Edge> edges;
vector<Edge> order;
bool incl[MX];
LL parent[MX][LOG];
LL maxw[MX][LOG];
LL depth[MX];

bool used[MX];

LL Find(LL a) {
    if (a == group[a]) {
        return a;
    }
    return group[a] = Find(group[a]);
}

void Union(LL a, LL b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (sze[a] < sze[b]) {
            swap(a, b);
        }
        group[b] = a;
        sze[a] += sze[b];
    }

}

void maxInCycle(LL n, LL m, LL l, LL r, LL &high, LL maxLog) {
    // l must be more deep than r
    if (depth[l] < depth[r]) {
        swap(l, r);
    }
    //high = max(high, maxw[l][0]);
    //high = max(high, maxw[r][0]);
    for (LL i = maxLog; i >= 0; i--) {
        if (depth[l] - (1 << i) >= depth[r]) {
            high = max(high, maxw[l][i]);
            l = parent[l][i];
        }
    }
    if (l == r) return;

    for (LL i = maxLog; i >= 0; i--) {
        if (parent[l][i] != -1 && parent[l][i] != parent[r][i]) {
            high = max(high, maxw[l][i]);
            high = max(high, maxw[r][i]);
            l = parent[l][i];
            r = parent[r][i];
                   }
    }
    high = max(high, maxw[l][0]);
    high = max(high, maxw[r][0]);
}

// Note dfs will never encounter visited node...
void dfs(LL v, LL w, LL dep, LL p) {
    if (used[v]) return;
    maxw[v][0] = w;
    depth[v] = dep;
    parent[v][0] = p;
    used[v] = true;
    for (pair<LL, LL> e : adj[v]) {
        LL u = e.first;
        if (used[u]) continue;
        LL w2 = e.second;
        dfs(u, w2, dep+1, v);
    }
}

void Debug(LL n, LL maxLog) {
    for (LL j = 0; j <= maxLog; j++) {
        for (LL i = 1; i <= n; i++) {
            cout << parent[i][j] << " ";
        }
        cout << endl;
    }
    cout << "maxw\n";
    for (LL j = 0; j <= maxLog; j++) {
        for (LL i = 1; i <= n; i++) {
            cout << maxw[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    LL n, m;
    cin >> n >> m;
    // Did not reserve enough in the first place...
    group.reserve(n+10);
    order.reserve(m+10);
    sze.reserve(n+10);

    for (LL i = 1; i <= n; i++) {
        group[i] = i;
        sze[i] = 1;
    }

    for (LL i = 1; i <= m; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
        edges.push_back({v, u, w, i});
        order[i] = {u, v, w, i};
    }
    LL total = 0;
    sort(edges.begin(), edges.end());

    // parent setup
    for (LL i = 1; i <= n; i++) {
        for (LL j = 0; j < LOG; j++) {
            parent[i][j] = -1;
        }
    }
    for (Edge e : edges) {
        if (Find(e.u) != Find(e.v)) {
            total += e.w;
            adj[e.u].push_back(make_pair(e.v, e.w));
            adj[e.v].push_back(make_pair(e.u, e.w));
            incl[e.idx] = true;
            Union(e.u, e.v);
        }
    }
    // Now kruskal is done, adj is MST + we have cost
    // Find root of tree
    /*
    LL par = -100;
    for (LL i = 1; i <= n; i++) {
        cout << i << "'s parent is " << parent[i][0] << "\n";
        if (parent[i][0] == -1) {
            par = i;
            //break;
        }
    }
    */

    // Dfs for depth counter + maxweight dp
    dfs(1, 0, 0, -1);

    // Binary lifting
    LL maxLog = -1;
    for (LL j = 1; (1 << j) < n; j++) {
        maxLog = j;
        for (LL i = 1; i <= n; i++) {
            if (parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
                // Keep the max of the weights so far (j-1)
                // to max of weights to the next ancestor
                maxw[i][j] = max(maxw[i][j-1], maxw[parent[i][j-1]][j-1]);
           }
        }
    }
    //Debug(n, maxLog);

    for (LL i = 1; i <= m; i++) {
        if (incl[i]) {
            cout << total << '\n';
        } else {
            // Add in new node, then find max in cycle,
            // then remove it
            Edge e = order[i];
            //adj[e.u].push_back(make_pair(e.v, e.w));
            LL high = 0;
            maxInCycle(n, m, e.u, e.v, high, maxLog);
            LL huh = total - high;
            LL huh2 = huh + e.w;
            //cout << total << " " << high << " " << e.w << endl;
            cout << huh2 << '\n';
            //adj[e.u].pop_back();
        }
    }
}





