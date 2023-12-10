class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> right;
        
        for (int i = 0; i < n; i++) {
            right[nums[i]] = i;
        }
        int ct = 1; int reach = 0;
        for (int i = 0; i < n; i++) {
            if (i > reach) {
                ct++;
                reach = right[nums[i]];
            }
            reach = max(reach, right[nums[i]]);
        }
        long long ans = 1;
        for (int i = 0; i < ct-1; i++) {
            ans *= 2;
            ans %= (int)1e9 + 7;
        }
        return ans;
    }
};

/*
every number will have it's leftmost and rightmost repeats. These
will all get grouped into ONE group. If there are overlaps, these
are all merged into one group as well. Then, we will just have
a bunch of distinct groups. We just run a normal formula on them
*/
