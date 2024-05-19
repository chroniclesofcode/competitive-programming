class Solution {
public:
    long long comb[35][35];
    int waysToReachStair(int k) {
        for (int i = 0; i <= 30; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j <= i-1; j++) {
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
        }
        long long curr = 1;
        int pw = 1;
        int ans = 0;
        for (int jp = 0; jp <= 29; jp++) {
            int diff = curr - k;
            if (diff >= 0 && jp+1 >= diff) {
                ans += comb[jp+1][diff];
            }
            curr += pw;
            pw *= 2;
        }
        return ans;
    }
};
