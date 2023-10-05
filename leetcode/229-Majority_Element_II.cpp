class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int MX = (int)1e9+1;
        int a = MX, ct1 = 0;
        int b = MX, ct2 = 0;
        for (int i = 0; i < n; i++) {
            if (a == nums[i]) {
                ct1++;
            } else if (b == nums[i]) {
                ct2++;
            } else if (ct1 == 0) {
                a = nums[i];
                ct1 = 1;
            } else if (ct2 == 0) {
                b = nums[i];
                ct2 = 1;
            } else {
                ct1--; ct2--;
            }
            cout << nums[i] << " a: " << a << " ct1: " << ct1 << " b: " << b << " ct2: " << ct2 << endl;
        }
        ct1 = 0;
        ct2  = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == a) {
                ct1++;
            } else if (nums[i] == b) {
                ct2++;
            }
        }
        if (ct1 > n/3) ans.push_back(a);
        if (ct2 > n/3) ans.push_back(b);
        return ans;
    }
};
