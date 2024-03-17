class Solution {
public:
    const static int MX = (int)1e5 + 1;
    int minimumDeletions(string word, int k) {
        unordered_map<int, int> m;
        for (auto c : word) m[c-'a']++;
        vector<int> res;
        int big = 0;
        for (auto &e : m) {
            res.push_back(e.second);
            big = max(big, e.second);
        }
        sort(res.begin(), res.end());
        int ans = INT_MAX;
        for (int i = 0; i <= big; i++) {
            int sub = 0, add = 0;
            for (auto r : res) {
                if (r < i) sub += r;
                if (r > i+k) add += r-(i+k);
            }
            ans = min(ans, sub + add);
        }
        return ans;
    }
};
