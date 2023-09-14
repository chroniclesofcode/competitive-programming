class Solution {
public:
    const static int MX = (int)20;
    int rev[MX];
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        for (auto& rel : relations) {
            rev[rel[1]-1] |= 1 << (rel[0]-1);
        }
        int LG = 1 << n;
        int INF = (int)1e9;
        vector<int> dp(LG, INF); // dp[i]: min sems to reach mask i
        dp[0] = 0;
        for (int mask = 0; mask < LG; mask++) {
            // note: when we reach mask, it should already be optimal
            if (dp[mask] == INF) continue;

            int can_study = 0; // bitmask of courses study-able
            for (int i = 0; i < n; i++) {
                // if course not studied yet and all prereqs completed
                if (!(mask & (1 << i)) && (mask & rev[i]) == rev[i]) { 
                    can_study |= (1 << i);
                }
            }

            if (__builtin_popcount(can_study) <= k) {
                dp[mask | can_study] = min(dp[mask | can_study], dp[mask] + 1);
            } else {
                // Trick to iterate through all combinations of positive bits of
                // can_study - just & with can_study and decrement.
                for (int comb = can_study; comb; comb = (comb - 1) & can_study) {
                    if (__builtin_popcount(comb) <= k) {
                        dp[mask | comb] = min(dp[mask | comb], dp[mask] + 1);
                    }
                }
            }
        }
        return dp.back();
    }
};
