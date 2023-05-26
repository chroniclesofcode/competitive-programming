class Solution {
public:
    vector<int> a[2001];
    bool v1[2001];
    bool v2[2001];

    bool dfs(int n) {
        if (v2[n]) {
            return true;
        }
        if (v1[n]) return false;
        v2[n] = true;
        v1[n] = true;
        for (int i = 0; i < a[n].size(); i++) {
            if (dfs(a[n][i])) {
                return true;
            }
        }
        v2[n] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) {
            a[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            int p = prerequisites[i][1];
            if (!v1[p] && dfs(p)) {
                return false;
            }
        }
        return true;
    }
};
