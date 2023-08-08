class Solution {
public:
    #define LL long long
    static const LL MX = 5 * 1e6;
    //const LL MOD = 1e7;

    int sz[MX];
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        for (int i = 0; i < n; i++) {
            grp[i] = i;
            sz[i] = 1;
        }
        int numc = 0;
        for (auto e : connections) {
            int u = e[0]; int v = e[1];
            if (Find(u) != Find(v)) {
                Union(u, v);
                numc++;
            }
        }
        int rem = connections.size() - numc;

        unordered_map<int, int> seen;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[Find(i)]) {
                ans++;
            }
            seen[Find(i)] = 1;
        }

        return (ans-1 > rem ? -1 : ans-1);
    }
};
