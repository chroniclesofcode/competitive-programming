class Solution {
public:
    const static int MX = 1001;
    unordered_set<int> s;
    unordered_map<int,int> k;
    unordered_map<int, int> vis;
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if ((nums[i]+nums[j]) % 2 == 1) continue;
                int val = abs(nums[i]-(nums[i]+nums[j])/2);
                k[val]++;
            }
        }
        for (auto it = k.begin(); it != k.end(); it++) {
            if (it->second >= n) {
                vector<int> test;
                unordered_map<int,int> m;
                int t = it->first;
                for (int i = 0; i < n; i++) {
                    if (m[nums[i]-2*t]) {
                        test.push_back(nums[i]-t);
                        m[nums[i]-2*t]--;
                    } else {
                        m[nums[i]]++;
                    }
                }
                if (test.size() == n/2) return test;
            }
        }
        return {};
    }
};
