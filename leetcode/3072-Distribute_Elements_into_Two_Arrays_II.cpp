class Solution {
public:
    const static int MX = (int)1e5 + 1;
    int BIT[MX+1], BIT2[MX+1];
    int n;
    void add(int x, bool one) {
        for (; x <= MX; x += x&-x) {
            if (one)
                BIT[x]++;
            else
                BIT2[x]++;
        }
    }
    int query(int x, bool one) {
        int sum = 0;
        for (; x > 0; x -= x&-x) {
            if (one)
                sum += BIT[x];
            else
                sum += BIT2[x];
        }
        return sum;
    }
    vector<int> resultArray(vector<int>& nums) {
        map<int, int> tmp;
        for (auto i : nums) {
            tmp[i] = 1;
        }
        int ct = 1;
        unordered_map<int,int> id;
        for (auto& e : tmp) {
            id[e.first] = ct++;
        }
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        add(id[nums[0]], true);
        arr2.push_back(nums[1]);
        add(id[nums[1]], false);
        for (int i = 2; i < nums.size(); i++) {
            // true is arr1, false is arr2
            int num = id[nums[i]];
            int gc1 = arr1.size()-query(num, true);
            int gc2 = arr2.size()-query(num,false);
            if (gc1 > gc2) {
                arr1.push_back(nums[i]);
                add(num, true);
            } else if (gc1 < gc2) {
                arr2.push_back(nums[i]);
                add(num, false);
            } else {
                if (arr2.size() < arr1.size()) {
                    arr2.push_back(nums[i]);
                    add(num, false);
                } else {
                    arr1.push_back(nums[i]);
                    add(num, true);
                }
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
