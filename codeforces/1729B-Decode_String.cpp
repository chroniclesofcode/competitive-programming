#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

void solve();

int main(void) {
    int t;
    cin >> t;

    while (t--) solve();

}

// ridiculously horrendous code, if this comment is still
// here, it means I didn't bother changing up the style
// Was in a bit of a hurry haha...

void solve() {
    int n;
    string s, output;
    cin >> n;
    cin >> s;
    int inc = 1;
    for (int i = n-1; i >= 0; i -= inc) {
        char tp[] = { s[i-2], s[i-1], '\0' };
        char tps[] = { s[i-1], '\0' };
        if (s[i] == '0') {
            int tmp = stoi(string(tp));
            int tmp2 = stoi(string(tps));
            if (tmp <= 26) {
                char c = tmp + 'a' - 1;
                output.push_back(c);
                inc = 3;
                continue;
            }
            if (tmp2 <= 26) {
                char c = tmp2 + 'a' - 1;
                output.push_back(c);
                inc = 2;
                continue;
            }
        }
        char c = s[i] - '0' + 'a' - 1;
        output.push_back(c);
        inc = 1;
    }
  
    reverse(output.begin(), output.end());
    cout << output << endl;
}


