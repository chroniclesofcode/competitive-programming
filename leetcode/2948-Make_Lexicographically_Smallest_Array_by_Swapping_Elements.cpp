class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> ans(nums.size());
        vector<array<int,2>> s;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            s.push_back({nums[i], i});
        }
        sort(s.begin(), s.end());
        int j = 0;
        vector<int> idx;
        idx.push_back(s[0][1]);
        for (int i = 1; i < n; i++) {
            if (s[i][0] - s[i-1][0] > limit) {
                sort(idx.begin(), idx.end());
                int ct = 0;
                while (j < i) {
                    ans[idx[ct++]] = s[j][0];
                    j++;
                }
                j = i;
                idx.clear();
                idx.push_back(s[i][1]); 
            } else {
                idx.push_back(s[i][1]);
            }
        }
        sort(idx.begin(), idx.end());
        int ct = 0;
        while (j < n) {
            ans[idx[ct++]] = s[j][0];
            j++;
        }
        return ans;
    }
};
/*
    sort nums, iterate through, if the previous number is within limit, then it is
    considered reachable. then just assign them to their slots in sorted order! that
    simple...
*/
