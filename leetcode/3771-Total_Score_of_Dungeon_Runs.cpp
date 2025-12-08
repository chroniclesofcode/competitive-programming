class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<int> p(n);
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += damage[i];
            p[i] = tmp;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int target = requirement[i];
            int lo = 0, hi = i;
            int idx = i + 1;
            while (lo <= hi) {
                int mid = lo + (hi-lo)/2;
                int loss = (mid == 0 ? p[i] : p[i] - p[mid-1]);
                int avail = hp - loss;
                if (avail >= target) {
                    hi = mid-1;;
                    idx = min(idx, mid);
                } else {
                    lo = mid+1;
                }
            }
            ans += (i - idx) + 1;
        }
        return ans;
    }
};

/*
    We can have list of original scores, say hp
    hp, hp, hp
    then have an array of subtractions
    -10, -5, -3, -8
    and for each one, we will prefix sum the entire thing
    and since it's monotonically decreasing, we can binary search?
*/