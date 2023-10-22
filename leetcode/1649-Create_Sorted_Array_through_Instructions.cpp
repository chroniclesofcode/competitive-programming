class Solution {
public:
    const static int MX = (int)1e5 + 2;
    const static int MD = (int)1e9 + 7;
    int large = 0;
    int n;
    int BIT[MX];
    void update(int idx) {
        for (; idx <= large; idx += idx&(-idx)) {
            BIT[idx]++;
        }
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx&(-idx)) {
            sum += BIT[idx];
        }
        return sum;
    }
    int createSortedArray(vector<int>& instructions) {
        n = instructions.size();
        for (int i = 0; i < n; i++) {
            large = max(large, instructions[i]);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int e = instructions[i];
            ans += min(query(e-1), query(large) - query(e));
            ans %= MD;
            update(e);
        }
        return ans;
    }
};
