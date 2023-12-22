class Solution {
public:
    static constexpr int MX = 11;
    double match = 0, tot = 0, sum = 0;
    double comb[MX][MX];
    vector<int> b;

    // pos = position in b (processed all or not), combined = sum of balls in each
    // ldist,ridst = left distincts, right distincts, perm = perms of this combo
    void dfs(int pos, int combined, int ldistinct, int rdistinct, double perm) {
        if (pos == b.size()) {
            if (combined == sum) {
                if (ldistinct == rdistinct) match += perm;
                tot += perm;
            }
            return;
        }
        // For this specific ball color, distribute ball[pos]. Cannot
        // distribute if not enough space for it. Note: sum is amount
        // of balls that can fit into one basket.
        for (int i = 0; i <= b[pos] && i + combined <= sum; i++) {
            // distribute current num of balls into left, rest into right!
            int ld = ldistinct + (i > 0); // don't inc if nothing to add!
            int rd = rdistinct + (b[pos] - i > 0);
            dfs(pos+1, i+combined, ld, rd, perm * comb[b[pos]][i]);
        }
    }

    double getProbability(vector<int>& balls) {
        b = balls;
        int n = b.size();
        sum = accumulate(balls.begin(), balls.end(), 0);
        for (int i = 0; i < MX; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
        }
        sum /= 2;
        dfs(0, 0, 0, 0, 1);
        return match / tot;
    }
};
