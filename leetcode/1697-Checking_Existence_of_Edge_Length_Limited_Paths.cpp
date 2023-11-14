class Solution {
public:
    #define arr3 array<int, 3>
    #define arr4 array<int, 4>
    static const int MX = (int)1e5 + 1;
    int grp[MX], sz[MX];
    vector<bool> ans;
    int Find(int a) {
        if (grp[a] == a) return a;
        return grp[a] = Find(grp[a]);
    }
    void Union(int a, int b) {
        a = Find(a); b = Find(b);
        if (a != b) {
            if (sz[b] > sz[a]) swap(a, b);
            sz[a] += sz[b];
            grp[b] = grp[a];
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        /*
            sort the queries based on limits, bfs using a pq and only
            traverse edges with a limit of the current lim. Union find
            all the nodes that are connected. Then, determine if the query
            is feasible (if both of the elements are part of the same group)
        */
        ans = vector<bool>(queries.size(), false);
        for (int i = 0; i < n; i++) {
            grp[i] = i; sz[i] = 1;
        }
        vector<arr4> qs;
        for (int i = 0; i < queries.size(); i++) {
            auto q = queries[i];
            qs.push_back({q[2], q[0], q[1], i});
        }
        sort(qs.begin(), qs.end());
        sort(edges.begin(), edges.end(), [](const auto a, const auto b) {
            return a[2] < b[2];
        });
        int i = 0;
        for (auto q : qs) {
            int lim = q[0], u = q[1], v = q[2], idx = q[3];
            for (; i < edges.size() && edges[i][2] < lim; i++) {
                Union(edges[i][0], edges[i][1]);
            }
            ans[idx] = Find(u) == Find(v);
        }
        return ans;
    }
};
