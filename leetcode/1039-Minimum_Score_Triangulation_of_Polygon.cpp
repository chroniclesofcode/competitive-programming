class Solution {
public:
    int dp[51][51];
    vector<int> v;

    // polygon from i->j
    int calc(int i, int j) {
        int ans = INT_MAX;
        if (j-i+1<3) return 0;
        if (j-i+1 == 3) return v[i]*v[i+1]*v[j];
        if (dp[i][j] > 0) return dp[i][j];
        for (int k = i+1; k <= j-1; k++) {
            ans = min(ans, calc(i,k)+calc(k,j)+v[i]*v[k]*v[j]);
        }
        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        v = std::move(values);
        return calc(0, v.size()-1);
    }
};
