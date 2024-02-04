class Solution {
public:
    int count[501][501];
    vector<vector<int>> resultGrid(vector<vector<int>>& img, int threshold) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < m-2; j++) {
                bool flag = false;
                for (int k = 0; k < 3; k++) {
                    if (abs(img[i+k][j]-img[i+k][j+1]) > threshold || abs(img[i+k][j+1]-img[i+k][j+2]) > threshold) {
                        flag = true;
                    }
                }
                if (flag) continue;
                for (int k = 0; k < 3; k++) {
                    if (abs(img[i][j+k]-img[i+1][j+k]) > threshold || abs(img[i+1][j+k]-img[i+2][j+k]) > threshold) {
                        flag = true;
                    }
                }
                if (flag) continue;
                int avg = 0;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        avg += img[i+x][j+y];
                    }
                }
                avg /= 9;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        ret[i+x][j+y] += avg;
                        count[i+x][j+y]++; 
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (count[i][j] == 0) {
                    ret[i][j] = img[i][j];
                } else {
                    ret[i][j] = ret[i][j] / count[i][j];
                }
            }
        }
        return ret;
    }
};
