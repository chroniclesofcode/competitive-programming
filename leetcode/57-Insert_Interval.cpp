class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& add) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        int st = add[0];
        int ed = add[1];
        while (i < n && intervals[i][1] < add[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= add[1]) {
            st = min(st, intervals[i][0]);
            ed = max(ed, intervals[i][1]);
            i++;
        }
        ans.push_back({st, ed});
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
