class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int j = 0;
        vector<vector<int>> cs(26);
        for (int i = 0; i < n; i++) {
            cs[s[i]-'A'].push_back(i);
        }
        int ans = 0;
        k = min(k, n);
        for (int i = 0; i < 26; i++) {
            int l = 0, ct = 0;
            for (int r = 0; r < cs[i].size(); r++) {
                ct++;
                while (cs[i][r]-cs[i][l]+1-ct > k) {
                    ct--;
                    l++;
                }
                int remain = k-(cs[i][r]-cs[i][l]+1-ct);
                ans = max(ans, min(cs[i][r]-cs[i][l]+1+remain,n));
            }
        }
        return ans;
    }
};
