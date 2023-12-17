class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int j = 0;
        long long ans = 0;
        int n = nums.size();
        long long tot = 0;
        long long small = 0, big = 0;
        long long prev = 0;
        for (int i = 0; i < n; i++) {
            big += nums[i];
            long long ct = i-j+1;
            long long med = ct/2;
            if (j+med > prev) {
                big -= nums[prev];
                small += nums[prev];
            }
            prev = j+med;
            long long curr = nums[j+med];
            long long cost = curr*((j+med)-j) - small + big - curr*(i-(j+med)+1);
            while (j < i && cost > k) {
                small -= nums[j];
                j++;
                ct = i-j+1; med = ct/2; curr = nums[j+med];
                if (j+med > prev) {
                    big -= nums[prev];
                    small += nums[prev];
                }
                prev = j+med;
                cost = curr*((j+med)-j) - small + big - curr*(i-(j+med)+1);
            }
            ans = max(ans, ct);
        }
        return ans;
    }
};
