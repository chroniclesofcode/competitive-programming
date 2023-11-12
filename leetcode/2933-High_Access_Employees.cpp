class Solution {
public:
    unordered_map<string, int> hi;
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), [](const vector<string> &x, const vector<string> &y) {
            return stoi(x[1]) < stoi(y[1]);
        });
        for (int i = 0; i < n; i++) {
            int ct = 0;
            for (int j = i+1; j < n; j++) {
                int orig = stoi(a[i][1]);
                int curr = stoi(a[j][1]);
                if (curr > orig + 100) break;
                if (a[i][0] != a[j][0]) continue;
                if (curr < orig + 100) {
                    ct++;
                }
            }
            if (ct >= 2) hi[a[i][0]] = 1;
        }
        vector<string> ans;
        for (auto &e : hi) {
            ans.push_back(e.first);
        }
        return ans;
    }
};
