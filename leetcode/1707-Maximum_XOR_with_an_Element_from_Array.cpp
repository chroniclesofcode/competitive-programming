class Solution {
public:
    #define arr array<int,3>
    const static int MX = (int)1e5 * 2 * 20;
    int tr[MX][2], c[MX], idx = 1; // optional end[MX]

    void addt(int num, int val) {
        int u = 1;
        for (int i = 31; i >= 0; i--) { // usually str.size()
            int bit = (num >> i) & 1;
            if (!tr[u][bit]) {
                tr[u][bit] = ++idx;
            }
            u = tr[u][bit];
            c[u] += val;
        }
    }

    int gett(int num) {
        int u = 1;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = !((num >> i) & 1);
            if (tr[u][bit] && c[tr[u][bit]] > 0) {
                u = tr[u][bit];
                res |= (bit << i);
            } else {
                u = tr[u][!bit];
                res |= (!bit << i);
            }
        }
        return num^res;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& _queries) {
        vector<int> ans(_queries.size(), 0);
        sort(nums.begin(), nums.end());
        vector<arr> queries;
        for (int i = 0; i < _queries.size(); i++) {
            queries.push_back({_queries[i][1], _queries[i][0], i});
        }
        sort(queries.begin(), queries.end());
        int j = 0;
        int nsz = nums.size();
        for (auto &q : queries) {
            if (q[0] < nums[0]) {
                ans[q[2]] = -1;
                continue;
            }
            while (j < nsz && nums[j] <= q[0]) {
                addt(nums[j], 1);
                j++;
            }
            ans[q[2]] = gett(q[1]);
        }
        return ans;
    }
};
/*
    sort nums, sort the queries by lim, so as you go up, you have all
    information. Keep everything in a trie while you are at it. Then
    traverse the best path on the trie to give you the solution.
*/


