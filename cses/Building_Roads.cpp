#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<int> cities[100001];
vector<int> visited(100001, 0);
vector<int> comp;
int ans;

// Run a DFS on every node for their connected component
// If not visited, set that as the representative node for
// that connected component. Then just iterate through the
// connected components and connect them in a list fashion

// NOTE: We do not need Kosaraju's algorithm since it is
// bidirectional links, otherwise we need to find the
// STRONGLY connected components
 
void dfs(int c) {
    if (visited[c]) {
        return;
    }
    visited[c] = 1;
    for (int i = 0; i < cities[c].size(); ++i) {
        dfs(cities[c][i]);
    }
}
 
int main(void) {
 
    cin >> n >> m;
 
 
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cities[x].push_back(y);
        cities[y].push_back(x);
    }
    
    for (int i = 0; i < n; ++i) {
        if (cities[i].size() == 0 || !visited[cities[i][0]]) {
            dfs(i);
            ans++;
            comp.push_back(i);
        }
    }
    cout << ans - 1 << endl;
    for (int i = 1; i < comp.size(); i++) {
        cout << comp[i-1] + 1 << " " << comp[i] + 1 << endl;
    }
    return 0;
}
 
