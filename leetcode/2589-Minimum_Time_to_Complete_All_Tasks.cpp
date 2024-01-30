class Solution {
public:
    int run[2001];
    int findMinimumTime(vector<vector<int>>& tasks) {
        vector<array<int,3>> iv;
        for (auto& t : tasks) {
            iv.push_back({ t[1], t[0], t[2] });
        }
        sort(iv.begin(), iv.end());
        int ans = 0;
        for (int i = 0; i < iv.size(); i++) {
            int u = iv[i][1], v = iv[i][0], dur = iv[i][2];
            int ct = 0;
            for (int j = v; j >= u; j--) {
                if (ct >= dur) break;
                if (run[j] == 1) ct++;
            }
            for (int j = v; j >= u; j--) {
                if (ct >= dur) break;
                if (run[j] == 0) {
                    run[j] = 1;
                    ans++;
                    ct++;
                } 
            }
        }
        return ans;
    }
};
