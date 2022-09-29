#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

const LL MAX = 2 * 1e5 + 10;
LL parent[MAX];
LL sz[MAX];

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

LL find_team(LL val) {
    if (val == parent[val]) {
        return val;
    }
    return parent[val] = find_team(parent[val]);
}

void merge_team(LL a, LL b) {
    a = find_team(a);
    b = find_team(b);
    if (a != b) {
        // a has to be > b;
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {  
    LL n, q;
    cin >> n >> q;
    vector<LL> next(n+10);
    for (LL i = 0; i < n + 10; i++) {
        parent[i] = i;
        sz[i] = 1;
        next[i] = i+1;
    }

    for (LL i = 0; i < q; i++) {
        LL type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            merge_team(x, y);
        } else if (type == 2) {
            while (x < y) {
                merge_team(x, y);
                LL tmp = next[x];
                next[x] = next[y];
                x = tmp;
            }
        } else if (type == 3) {
            cout << (find_team(x) == find_team(y) ? "YES" : "NO") << "\n";
        }
        /*
        cout << i << " command: " << type << " " << x << " " << y << endl;
        cout << "next: ";
        for (int j = 0; j < n; j++) {
            cout << next[j] << " ";
        }
        cout << endl;
        */
    }
}






