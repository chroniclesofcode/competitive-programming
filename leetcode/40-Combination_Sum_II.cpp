class Solution {
public:
    vector<vector<int>> ans;
    vector<int> c, curr;
    void calc(int start, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < c.size(); i++) {
            if (target - c[i] >= 0) {
                curr.push_back(c[i]);
                calc(i+1, target - c[i]);
                curr.pop_back();
            }
            while (i < c.size()-1 && c[i] == c[i+1]) i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        c = std::move(candidates);
        sort(c.begin(), c.end());
        calc(0, target);
        return ans;
    }
};
