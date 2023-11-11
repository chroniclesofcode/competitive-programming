class Solution {
public:
    #define LL long long
    unordered_map<int, int> x, y, rx, ry;
    vector<int> tx, ty;
    int dp[401][401];
    int rectangleArea(vector<vector<int>>& rectangles) {
        /*
            we want to do a dp: where dp[x][y] = 1 if it's written over.
            Simple, iterate over all rectangles, set all dp[i][j]=1. 
            We cant do this since bounds are massive unless... coordinate
            compression. We just do this, but with weird numbers.
        */
        for (auto r : rectangles) {
            tx.push_back(r[0]);
            ty.push_back(r[1]);
            tx.push_back(r[2]);
            ty.push_back(r[3]);
        }
        sort(tx.begin(), tx.end());
        sort (ty.begin(), ty.end());
        int ct = 0;
        for (int i = 0; i < tx.size(); i++) {
            rx[i] = tx[i];
            x[tx[i]] = i;
        }
        for (int i = 0; i < ty.size(); i++) {
            ry[i] = ty[i];
            y[ty[i]] = i;
        }
        for (int i = 0; i < rectangles.size(); i++) {
            auto r = rectangles[i];
            for (int j = x[r[0]]; j < x[r[2]]; j++) {
                for (int k = y[r[1]]; k < y[r[3]]; k++) {
                    dp[j][k] = 1;
                }
            }
        }
        int n = tx.size(), m = ty.size();
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j]) {
                    ans += (LL)(rx[i+1]-rx[i]) * (ry[j+1]-ry[j]);
                    ans %= (int)1e9+7;
                }
            }
        }
        return ans;
    }
};
