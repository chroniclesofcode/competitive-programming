class Solution {
public:
    static const int MX = 2*(int)1e5 + 1;
    int left[MX][2];
    int right[MX][2];
    int minimumTime(string s) {
        /*
        left/right[i][0/1] -> 
        0: cost of removing it if you just take it off the left/right side
        which is just the distance from left.
        1: cost of removing it if you magically remove it, which is the cost
        of the closest 1 on the left/right + 2
        Iterate through and just take some combination of left + right.
        */
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                left[i][0] = i+1;
                left[i][1] = 2 + ((i > 0) ? min(left[i-1][0], left[i-1][1]) : 0);
            } else {
                left[i][0] = i > 0 ? left[i-1][0] : 0;
                left[i][1] = i > 0 ? left[i-1][1] : 0;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') {
                right[i][0] = n-i;
                right[i][1] = 2 + ((i < n-1) ? min(right[i+1][0], right[i+1][1]) : 0);
            } else {
                right[i][0] = i < n-1 ? right[i+1][0] : 0;
                right[i][1] = i < n-1 ? right[i+1][1] : 0;
            }
        }
        int ans = min({right[0][0], right[0][1], left[n-1][1], left[n-1][0]});
        int beg = 0;
        for (int i = 0; i < n-1; i++) {
            if (!beg && s[i] == '0') {
                continue;
            } 
            beg = 1;
            ans = min(ans, min(left[i][0],left[i][1]) + min(right[i+1][0],right[i+1][1]));
        }
        return ans;
    }
};
