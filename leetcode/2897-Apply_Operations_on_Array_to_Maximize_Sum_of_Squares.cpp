class Solution {
public:
    int bit[32];
    int maxSum(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                bit[j] += (nums[i] >> j) & 1;
            }
        }
        for (int i = 0; i < 32; i++) {
            bit[i] = min(bit[i], k);
        }
        long long ans = 0;
        long long mask;
        for (int i = 0; i < k; i++) {
            mask = 0;
            for (int j = 0; j < 32; j++) {
                if (bit[j] > 0) {
                    mask |= 1 << j;
                    bit[j]--;
                }
            }
            ans += mask * mask;
            ans %= (int)1e9 + 7;
        }
        return ans;
    }
};

/*
    we want to maximize the greatest sum of the first
    k elements, everything else we don't care if they
    go to 0, just use them up. Within the first k as well,
    it is worth to combine them if the final result will provide
    a greater sum of squares.

*/
