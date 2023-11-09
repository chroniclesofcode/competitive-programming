class Solution {
public:
    unordered_map<int, int> ct;
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans(puzzles.size());
        for (int i = 0; i < words.size(); i++) {
            int mask = 0;
            for (auto ch : words[i]) {
                mask |= 1 << (int)(ch-'a');
            }
            ct[mask]++;
        }
        for (int i = 0; i < puzzles.size(); i++) {
            int mask = 0;
            for (auto ch : puzzles[i]) {
                mask |= 1 << (int)(ch-'a');
            }
            int first = puzzles[i][0]-'a';
            int fixed = ~mask;
            mask = 0;
            do {
                if (mask & (1 << first)) {
                    ans[i] += ct[mask];
                }
                mask = ((mask | fixed) + 1) & ~fixed;
            } while (mask != 0);
        }
        return ans;
    }
};
