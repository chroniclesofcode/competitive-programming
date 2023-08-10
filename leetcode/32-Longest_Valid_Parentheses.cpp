class Solution {
public:
    /*
       Very simple stuff. Just remove every single infected node
       one by one, and check how many nodes will be infected via
       dfs. The bounds are low, so this question is ridiculously
       easy since it's pretty much brute force.
    */
    int n;
    vector<bool> vis = vector<bool>(301, false);
    void infect(vector<vector<int>>& g, int u, int exclude, int &ct) {
        if (vis[u]) return;
        //cout << "infected " << u << " excluding " << exclude << " ct: " << ct << endl;
        vis[u] = true;
        ct++;
        for (int i = 0; i < n; i++) {
            if (i == exclude) continue;
            if (!vis[i] && g[u][i]) infect(g, i, exclude, ct);
        }
        return;
    }
    int minMalwareSpread(vector<vector<int>>& g, vector<int>& initial) {
        n = g.size();
        int ans = numeric_limits<int>::max();
        int ret = 0;
        sort(initial.begin(), initial.end());
        for (int vi : initial) {
            int ct = 0;
            vis.assign(vis.size(), false);
            for (int u : initial) {
                if (u == vi) continue;
                infect(g, u, vi, ct);
            }
            //cout << "ct: " << ct << " for " << vi << endl;
            if (ct < ans) {
                ans = ct;
                ret = vi;
            }
        }
        return ret;
    }
};
