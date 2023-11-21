class Solution {
public:
    unordered_map<int, int> ct;
    int comb[1100];
    int dp[55][1100];
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ct[nums[i]]++;
        }
        vector<int> occ;
        for (auto it : ct) {
            occ.push_back(it.second);
        }
        int m = occ.size(); // can only be 50
        int qsz = quantity.size(); // can only be 10
        int LG = 1 << qsz; // can only be 1024
        // all combinations of quantities, assigned. We then run a
        // dp and say for this value (occurence), we assign this
        // bitset of quantities to you. Propagate a future state.
        for (int i = 0; i < LG; i++) {
            for (int j = 0; j < qsz; j++) {
                if (i & (1 << j)) {
                    comb[i] += quantity[j];
                }
            }
        }
        // for every occurence, what happens if we assign a certain
        // bitset of quantities to it?
        // using occ 0..i, can we make mask j in groups?
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < LG; j++) {
                // If we can't j using 0..i-1, how can we do it with 0..i?
                if (i > 0 && !dp[i-1][j]) continue;
                if (i == 0 && j != 0) continue;
                dp[i][j] = 1;
                if (j == LG-1) continue;
                // grab all unset groups (j is all 'done' groups)
                int unset = j^(LG-1);
                // iterate through all unset groups, and assign to i
                for (int k = unset; k > 0; k--) {
                    k = k & unset; // dont take extra groups
                    if (comb[k] <= occ[i]) {
                        dp[i][j|k] = true;
                    }
                }
            }
        }

        return dp[m-1][LG-1];
    }
};
