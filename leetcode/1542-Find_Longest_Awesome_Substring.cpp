class Solution {
public:
    int longestAwesome(string s) {
        int ans = 0;
        int mask = 0;
        unordered_map<int, int> last;
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - '0';
            mask ^= 1 << ch;
            if (mask == 0) ans = i+1;
            else if (last[mask] > 0) ans = max(ans, i+1-last[mask]);
            else last[mask] = i+1;
            for (int j = 0; j < 10; j++) {
                int tmp = mask^(1<<j);
                if (tmp == 0) ans = i+1;
                else if (last[tmp] > 0) ans = max(ans,i+1-last[tmp]);
            }
        }
        return ans;
    }
};
