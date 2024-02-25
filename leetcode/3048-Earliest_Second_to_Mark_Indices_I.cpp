class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& ci) {
        int lo = 0, hi = ci.size()-1;
        int ans = ci.size();
        int n = nums.size();
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            vector<int> a(nums.size(), -1);
            for (int i = 0; i <= mid; i++) {
                a[ci[i]-1] = i;
            }
            bool flag = false;
            vector<array<int,2>> b;
            for (int i = 0; i < n; i++) {
                if (a[i] == -1) {
                    flag = true; break;
                }
                b.push_back({a[i], i});
            }
            if (flag) {
                lo = mid+1;
                continue;
            }
            int tot = 0;
            sort(b.begin(), b.end());
            for (int i = 0; i < a.size(); i++) {
                int time = b[i][0], idx = b[i][1];
                tot += nums[idx];
                if (tot > time) {
                    flag = true; break;
                }
                tot++;
            }
            if (flag) {
                lo = mid+1;
            } else {
                hi = mid-1;
                ans = min(ans, mid);
            }
        }
        return (ans == ci.size() ? -1 : ans+1);
    }
};

/*
1 indexed
add all the last occurences of each element into an array. This is the
time that you have to complete each one. You will greedily iterate
through all the last occs, and see if it is possible to reduce them.
binary search this value in M.
*/
