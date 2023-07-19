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
const LL MX = 5 * 1e3;
//const LL MOD = 1e7;

int sz[MX], adj[MX][MX], vis[MX];
int grp[MX]; 

int Find(int a) {
    if (a == grp[a]) {
        return a;
    }
    return grp[a] = Find(grp[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        grp[b] = a;
        sz[a] += sz[b];
    }

}

int n;

/*

*/

void solve() {
    #define arr array<int,2>
    cin >> n;
    int z1, z2;
    for (int i = 0; i < n-1; i++) {
        cin >> z1 >> z2;
        z1--; z2--;
        adj[z1][z2] = 1;
        adj[z2][z1] = 1;
    }
    for (int i = 0; i < n; i++) {
        grp[i] = i;
    }
    vector<arr> rm;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adj[i][j]) {
                if (Find(i) != Find(j)) {
                    Union(i, j);
                } else {
                    rm.push_back({i, j});
                }
            }
        }
    }
    vector<arr> build;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (!adj[i][j]) {
                if (Find(i) != Find(j)) {
                    Union(i, j);
                    build.push_back({i , j});
                } 
            }
        }
    }
    cout << rm.size() << endl;
    for (int i = 0; i < rm.size(); i++) {
        cout << rm[i][0]+1 << ' ' << rm[i][1]+1 << ' ' << build[i][0]+1 << ' ' << build[i][1]+1 << '\n';
    }
}





