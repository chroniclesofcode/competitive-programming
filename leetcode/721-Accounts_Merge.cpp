class Solution {
public:
    const static int MX = 1005;
    int sz[MX];
    int grp[MX]; 
    bool vis[MX];

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (int i = 0; i < MX; i++) {
            grp[i] = i;
            sz[i] = 1;
        }

        int ct = 1;
        unordered_map<string, int> emid; // email to id
        unordered_map<int, string> idname;
        for (auto accs : accounts) {
            int id = ct++;
            idname[id] = accs[0];
            for (int i = 1; i < accs.size(); i++) {
                if (emid[accs[i]] > 0) {
                    Union(emid[accs[i]], id);
                } else {
                    emid[accs[i]] = id;
                }
            }
        }
        ct = 1;
        unordered_map<int, set<string>> mails;
        for (auto accs : accounts) {
            int id = ct++;
            for (int i = 1; i < accs.size(); i++) {
                mails[Find(id)].insert(accs[i]);
            }
        }

        vector<vector<string>> ans;
        for (int i = 1; i <= accounts.size(); i++) {
            if (vis[Find(i)]) continue;
            vis[Find(i)] = 1;
            vector<string> add = { idname[Find(i)] };
            for (auto it = mails[Find(i)].begin(); it != mails[Find(i)].end(); it++) {
                add.push_back(*it);
            }
            ans.push_back(add);
        }
        return ans;
    }
};
