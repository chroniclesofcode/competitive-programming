class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> num;
        num.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) num.push_back(nums[i]);
        }
        int j = 0;
        int ans = INT_MAX;
        for (int i = 0; i < num.size(); i++) {
            while (num[i]-num[j] > n-1) {
                j++;
            }
            ans = min(ans, n - (i-j+1));
        }
        return ans;
    }
};
// 4 5 8 8 9 9
