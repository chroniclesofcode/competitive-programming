class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long totneg = 0;
        for (int i = 0; i < transactions.size(); i++) {
            if (transactions[i][0] > transactions[i][1]) {
                totneg += transactions[i][0] - transactions[i][1];
            }
        }
        long long ans = 0;
        for (int i = 0; i < transactions.size(); i++) {
            long long tmp = totneg;
            if (transactions[i][0] > transactions[i][1])
                tmp -= transactions[i][0] - transactions[i][1];
            tmp += transactions[i][0];
            ans = max(ans, tmp);
        }
        return ans;
    }
};
