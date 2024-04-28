class Solution {
public:
    #define LL long long
    long long minEnd(int n, int x) {
        int nn = n-1;
        int j = 0; // for x
        long long ans = x;
        long long tmp = x;
        for (int i = 0; i < 64; i++) {
            while (j < 64 && (1LL << j) & tmp) j++;
            if (nn & (1LL << i)) {
                ans |= 1LL << j;
            }
            j++;
        }
        return ans;
    }
};
