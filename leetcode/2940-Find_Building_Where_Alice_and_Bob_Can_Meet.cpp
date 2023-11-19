class Solution {
public:
    static const int mx = 5 * (int)1e4 + 1;
    set<int> s;
    #define arr3 array<int,3>
    #define arr2 array<int,2>
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<vector<int>> rq;
        vector<int> ans(queries.size());
        int n = heights.size();
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] < queries[i][1]) swap(queries[i][1], queries[i][0]);
            rq.push_back({queries[i][0], queries[i][1], i});
        }
        sort(rq.begin(), rq.end());
        int j = heights.size()-1;
        deque<arr2> dq;
        for (int i = rq.size()-1; i >= 0; i--) {
            while (j >= rq[i][0]) {
                while (dq.size() && heights[j] >= dq.front()[0]) dq.pop_front();
                dq.push_front({ heights[j], j});
                j--;
            }

            if (rq[i][0] == rq[i][1]) {
                ans[rq[i][2]] = rq[i][0];
                continue;
            }
            int idx = rq[i][2];
            arr2 big = {heights[rq[i][1]], INT_MAX};
            auto it = upper_bound(dq.begin(), dq.end(), big);
            if (it == dq.end()) ans[idx] = -1;
            else ans[idx] = (*it)[1];
        }
        return ans;
    }
};
