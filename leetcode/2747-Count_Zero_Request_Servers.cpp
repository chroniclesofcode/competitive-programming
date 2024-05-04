class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        for (int i = 0; i < logs.size(); i++) swap(logs[i][0], logs[i][1]);
        sort(logs.begin(), logs.end());
        vector<array<int,2>> qu;
        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            qu.push_back({queries[i], i});
        }
        sort(qu.begin(), qu.end());

        int fr = 0, bk = 0;
        int distinct = 0;
        vector<int> vis(n+1, 0);
        for (int i = 0; i < qu.size(); i++) {
            int time = qu[i][0], idx = qu[i][1];
            while (fr < logs.size() && logs[fr][0] <= time) {
                int id = logs[fr][1];
                vis[id]++;
                if (vis[id] == 1) distinct++;
                fr++;
            }
            while (bk < fr && logs[bk][0] < time - x) {
                int id = logs[bk][1];
                vis[id]--;
                if (vis[id] == 0) distinct--;
                bk++;
            }
            ans[idx] = n - distinct;
        }
        return ans;
    }
};

/*
[1,2],[1,3],[2,1],[4,2]
*/