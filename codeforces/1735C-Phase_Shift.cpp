#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    LL t;
    cin >> t;
    while (t--) {
        solve();
    }
}

const int MAXSZ = 2 * 1e5;

int group[26];
int gsize[26];

int Find(int a) {
    if (a == group[a]) {
        return a;
    }
    return group[a] = Find(group[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (gsize[a] < gsize[b]) {
            swap(a, b);
        }
        group[b] = a;
        gsize[a] += gsize[b];
    }

}

void solve() {
    int n;
    cin >> n;
    string t;
    cin >> t;

    for (int i = 0; i < 26; i++) {
        group[i] = i;
        gsize[i] = 1;
    }

    /*
       create array of characters that say what each character
       links to

       keep a variable count of the smallest character we want to link to

       for every letter in t:
       - check if the smallest one works else increment
       works if: 
       Not in same group, can only link with first if only 1 group


    */

    vector<char> a(26, '0');
    vector<char> b(26, '0');

    for (int c : t) {
        int curr = c - 'a';

        // If it already has assigned value
        if (a[curr] != '0') {
            //cout << "POG";
            cout << (char)(a[curr] + 'a');
        } else {
            for (int i = 0; i < 26; i++) {
                if (b[i] != '0') continue;
                if (curr == i) continue;
                // Note = 26 because EVERY single node is part of
                // the union at the very end, but the two ends aren't
                // 'connected'. So do not put 25.
                if (Find(curr) == Find(i) && gsize[Find(curr)] != 26) continue;
                //cout << (char)(curr + 'a') << " maps to " << (char)(i+'a') << endl;
                a[curr] = i;
                b[i] = curr;
                Union(curr, i);
                cout << (char)(i + 'a');
                break;
            }
        }
    }
    cout << '\n';

}

