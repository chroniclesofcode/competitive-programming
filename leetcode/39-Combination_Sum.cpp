class Solution {
public:
    vector<int> c, curr;
    vector<vector<int>> ans;
    void calc(int start, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < c.size(); i++) {
            if (target - c[i] >= 0) {
                curr.push_back(c[i]);
                calc(i, target - c[i]);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        c = std::move(candidates);
        calc(0, target);
        return ans;
    }
};
