class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        int mx = 0;
        int mval = -1;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
            if (m[nums[i]] > mx) {
                mx = m[nums[i]];
                mval = nums[i];
            }
        }
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mval) {
                ct++;
            }
            if (i != n-1 && ct*2 > (i+1) && (mx-ct)*2 > (n-i-1)) {
                return i;
            }
        }
        return -1;
    }
};
