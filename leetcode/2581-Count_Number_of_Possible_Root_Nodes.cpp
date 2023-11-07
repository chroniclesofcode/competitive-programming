class Solution {
public:
    static const int MX = (int)1e5+2;
    //int dp[MX]; // how many guesses are true for root
    // Big issues with unordered_map, because dupes, m[1]=5 but also m[1]=7.
    //unordered_map<int, int> isg;
    unordered_map<int, unordered_map<int,int>> isg;
    vector<int> adj[MX]; // edge to
    int ans = 0;
    int ct = 0;
    int k;
    void init(int u, int p) {
        for (int v : adj[u]) {
            if (v == p) continue;
            ct += isg[u][v];
            init(v, u);
        }
    }

    void dfs(int u, int p, int tot) {
        if (tot >= k) ans++;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, tot - (isg[u][v]) + (isg[v][u]));
        }
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int _k) {
        /*
            for each root, store how many guesses are true for it.
            Do initial dfs, orient all the edges some way according to arbitrary 
            root, e.g. 0. Now, iterate through all guesses and count how many
            are already oriented correctly. Also mark which edges are guesses.
            Now, iterate through the graph again and update the ans for each node,
            when you pass over an edge, it will be flipped - so answer will be
            tot correct + par incorrect - par correct.
        */
        k = _k;
        for (vector<int> g : guesses) {
            //isg[g[1]+1] = g[0]+1;
            isg[g[0]][g[1]] = 1;
        }
        for (vector<int> e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        init(0, -1);
        dfs(0, -1, ct);
        return ans;
    }
};
