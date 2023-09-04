class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int right[n];
        int left[n];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, height[i]);
            left[i] = ans;
        }
        ans = 0;
        for (int i = n-1; i >= 0; i--) {
            ans = max(ans, height[i]);
            right[i] = ans;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += max(min(left[i], right[i]) - height[i], 0);
        }
        return ret;
    }
};
