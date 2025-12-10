class Solution {
public:
    #define arr2 array<int,2>
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<arr2> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i][0] = technique1[i] - technique2[i];
            diff[i][1] = i;
        }
        sort(diff.begin(), diff.end(), greater<arr2>());
        long long ans = 0;
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            int idx = diff[i][1];
            if (i < k) {
                ans += technique1[idx];
                continue;
            }
            ans += (max(technique1[idx], technique2[idx]));
        }
        return ans;
    }
};