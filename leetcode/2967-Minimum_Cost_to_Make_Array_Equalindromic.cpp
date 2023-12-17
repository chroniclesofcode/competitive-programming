class Solution {
public:
    bool isp(int x) {
        string s = to_string(x);
        for (int i = 0; i <= s.size()/2; i++) {
            if (s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    }
    long long check(vector<int> &nums, int comp) {
        long long ans = 0;
        for (auto i : nums) {
            ans += abs(comp-i);
        }
        return ans;
    }

    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n/2];
        int lo = med, hi = med;
        while (!isp(lo)) lo--;
        while (!isp(hi)) hi++;
        return min(check(nums,lo), check(nums,hi));
    }
};
