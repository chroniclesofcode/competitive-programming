class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> sfl;
        for (int i = 0; i < mentors.size(); i++) {
            sfl.push_back(i);
        }

        int ans = 0;
        do {
            int sum = 0;
            for (int i = 0; i < students.size(); i++) {
                for (int k = 0; k < mentors[0].size(); k++) {
                    if (mentors[sfl[i]][k] == students[i][k]) {
                        sum++;
                    }
                }
            }
            ans = max(ans, sum);
        } while (next_permutation(sfl.begin(), sfl.end()));
        return ans;
    }
};
