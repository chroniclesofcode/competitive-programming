#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prt_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr LL INF = (LL)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

int n, m, k, sz[MX], rem[MX], activated[MX];
vector<int> adj[MX];
vector<pair<int,int>> anc[MX]; // { ancestor, distance }
struct {
    int h1 = 0, h2 = 0, hchild = 0;
} ans[MX];

int get_subt(LL u, LL p) {
    sz[u] = 1;
    for (LL v : adj[u]) {
        if (v == p || rem[v]) continue;
        sz[u] += get_subt(v, u);
    }
    return sz[u];
}

int centroid(LL u, LL p, LL tot) {
    for (LL v : adj[u]) {
        if (v == p || rem[v]) continue;
        if (sz[v] > tot/2) return centroid(v, u, tot);
    }
    return u;
}

void process_subt(LL u, LL p, LL c, LL dep) {
    for (LL v : adj[u]) {
        if (v == p || rem[v]) continue;
        dep++;
        process_subt(v, u, c, dep);
        dep--;
    }
    anc[u].push_back({c, dep});
}

void centroid_decomp(LL node = 0) {
    LL c = centroid(node, -1, get_subt(node, -1));
    rem[c] = true;
    
    // Add logic here
    for (LL v : adj[c]) {
        if (rem[v]) continue;
        process_subt(v, c, c, 1);
    }

    for (LL v : adj[c]) {
        if (rem[v]) continue;
        centroid_decomp(v);
    }
}


void update(int u) {
    int prev = u;
    activated[u] = 1;
    for (int i = anc[u].size()-1; i >= 0; i--) {
        auto &[a, dep] = anc[u][i];
        auto &data = ans[a];
        if (dep > data.h1) {
            if (prev != data.hchild) {
                data.h2 = data.h1;
            }
            data.h1 = dep;
            data.hchild = prev;
        } else if (prev != data.hchild && dep > data.h2) {
            data.h2 = dep;
        }
        prev = a;
    }
}

int query(int u) {
    int prev = u;
    int ret = ans[u].h1;
    for (int i = anc[u].size()-1; i >= 0; i--) {
        auto &[a, dep] = anc[u][i];
        auto &data = ans[a];
        if (!activated[a]) {
            prev = a;
            continue;
        }
        if (data.hchild != prev) {
            // if it's a diff subtree, you can do u
            // to centroid, centroid to height
            ret = max(ret, dep + data.h1);
        } else {
            // else to second highest...
            ret = max(ret, dep + data.h2);
        }
        prev = a;
    }
    return ret;
}

void solve() {
    ifstream cin("newbarn.in"); ofstream cout("newbarn.out");
    cin >> n; 
    vector<arr2> qs;
    int curr = 1;
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        char op; int b;
        cin >> op >> b;
        if (op == 'B') {
            qs.push_back({1, b});
            if (b != -1) {
                adj[b].push_back(curr);
                adj[curr].push_back(b);
            } else {
                roots.push_back(curr);
            }
            curr++;
        } else if (op == 'Q') {
            qs.push_back({0, b});
        }
    }
    for (auto r : roots) {
        centroid_decomp(r);
    }
    curr = 1;
    for (auto &cmd : qs) {
        
        if (cmd[0] == 1) {
            // build
            update(curr);
            curr++;
        } else {
            // query
            cout << query(cmd[1]) << '\n';
        }
    }
}


