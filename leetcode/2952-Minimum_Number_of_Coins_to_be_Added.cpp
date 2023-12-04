class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long long n = coins.size();
        long long ans = 0;
        long long sum = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (sum + 1 < coins[i]) {
                ans++;
                sum += sum+1;
            }
            sum += coins[i];
        }
        while (sum < target) {
            sum += sum+1;
            ans++;
        }
        return ans;
    }
};
