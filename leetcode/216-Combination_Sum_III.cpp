class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    int lim;
    void calc(int start, int ct, int target) {
        if (ct == lim && target == 0) {
            ans.push_back(curr);
            return;
        }
        if (ct == lim) return;
        for (int i = start; i <= 9; i++) {
            if (target - i >= 0) {
                curr.push_back(i);
                calc(i+1, ct+1, target - i);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        lim = k;
        calc(1, 0, n);
        return ans;
    }
};
