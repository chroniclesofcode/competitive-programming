class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        #define LL long long
        LL n = nums.size();
        
        LL sum = 0;
        for (LL i = 0; i < n; i++) {
            sum += nums[i];
        }
        LL mult = (target / sum) * n;
        LL nt = target % sum;

        if (nt == 0) return mult;
        if (target == sum) {
            return nums.size();
        } else if (target > sum) {
            // it's connected to the left OR the right, take the min!
            LL ans = INT_MAX;
            LL run = 0;
            for (LL i = 0; i < n; i++) {
                run += nums[i];
                if (run == nt) {
                    ans = min(ans, mult+i+1);
                    break;
                }   
            }
            run = 0;
            for (LL i = n-1; i >= 0; i--) {
                run += nums[i];
                if (run == nt) {
                    ans = min(ans, mult+n-i);
                }
            }
            run = 0;
            for (LL i = 0; i < n; i++) {
                nums.push_back(nums[i]);
            }
            LL len = ans;
            LL j = 0;
            for (LL i = 0; i < nums.size(); i++) {
                run += nums[i];
                if (run == nt) {
                    len = min(len, mult+i-j+1);
                    run -= nums[j];
                    j++;
                } else if (run > nt) {
                    while (run > nt && j < i) {
                        run -= nums[j];
                        j++;
                    }
                    if (run == nt) {
                        len = min(len, mult+i-j+1);
                        run -= nums[j];
                        j++;
                    }
                }
            }
            
            return len == INT_MAX ? -1 : len;
        } else {
            // less than sum, it has to be a subarray inside (slide window)
            LL len = INT_MAX;
            LL j = 0;
            LL run = 0;
            for (LL i = 0; i < n; i++) {
                nums.push_back(nums[i]);
            }
            for (LL i = 0; i < nums.size(); i++) {
                run += nums[i];
                if (run == target) {
                    len = min(len, i-j+1);
                    run -= nums[j];
                    j++;
                } else if (run > target) {
                    while (run > target && j < i) {
                        run -= nums[j];
                        j++;
                    }
                    if (run == target) {
                        len = min(len, i-j+1);
                        run -= nums[j];
                        j++;
                    }
                }
            }
            
            return len == INT_MAX ? -1 : len;
        }
        
        
        return -1;
    }
};

