class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_map<int, int>> block;
        for (auto &o : obstacles) {
            block[o[0]][o[1]] = 1;
        }
        int x = 0, y = 0;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int ans = 0;
        int currdir = 0;
        for (auto &c : commands) {
            if (c == -1) {
                currdir++;
            } else if (c == -2) {
                currdir--;
            } else if (1 <= c && c <= 9) {
                for (int i = 1; i <= c; i++) {
                    int nx = x + dirs[currdir][0], ny = y + dirs[currdir][1];
                    if (block[nx][ny]) continue;
                    swap(x, nx);
                    swap(y, ny);
                    ans = max(ans, x*x + y*y);
                }
            }
            currdir = (currdir%4 + 4)%4;
        }
        return ans;
    }
};
