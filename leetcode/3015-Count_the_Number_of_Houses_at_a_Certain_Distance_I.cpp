class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                int dist = j-i;
                dist = min(dist, abs(i-x) + 1 + abs(j-y));
                dist = min(dist, abs(i-y) + 1 + abs(j-x));
                ans[dist-1] += 2;
            }
        }
        return ans;
    }
};
