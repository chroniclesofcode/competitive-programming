class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long avg = 0;
        long long ans = 0;
        long long tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            avg += nums[i];
            tmp = avg/(i+1);
            if (avg % (i+1) != 0) tmp++;
            ans = max(ans, tmp);
        }
        return ans;
    }
};
