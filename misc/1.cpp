#include <bits/stdc++.h>

using namespace std;

void solve();


#define LL long long
int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

void solve() {
    int m, n;
    cin >> m >> n;
    char image[3*m][3*n];
    for (int i = 0; i < 3*m; ++i) {
        for (int j = 0; j < 3*n; ++j) {
            cin >> image[i][j];
        }
    }
    int beg = 0, end = 0;
    int white, black;
    while (beg < 3*m - 1) {
        white = 0; black = 0;
        for (int i = beg; i < beg+3; ++i) {
            for (int j = end; j < end+3; ++j) {
                if (image[i][j] == '.') white++;
                else black++;
            }
        }
        //cout << "white: " << white << " black: " << black << " beg: " << beg << " end: " << end << endl;
        if (white >= black) cout << '.';
        else cout << '*';

        end += 3;

        if (end >= 3*n - 1) {
            cout << "\n";
            end = 0;
            beg += 3;
        }
    }
}
   
