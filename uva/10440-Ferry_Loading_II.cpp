#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

void solve();

int main(void) {

    int c;
    cin >> c;

    while (c--) {
        solve();
    }

}

// Basically, the whole point of this question is that there
// is a case where you shouldn't load up your entire boat
// at once early on so that you don't arrive after the last car has
// arrived. To account for this, we take the modulo m%n and make the 
// boat's first leaving at the very beginning so that you will always
// have a divisor of m boats left. 
// This means hopefully, you will be able to make your last departure
// at exactly when the last car arrives, and no more.


void solve() {
    int n, t, m;
    cin >> n >> t >> m;
    vector<int> arrivals(m);
    for (int i = 0; i < m; i++) cin >> arrivals[i];
    sort(arrivals.begin(), arrivals.end());
    int trips = 0;
    int currtime = 0;
    int i;
    if (m % n == 0) {
        i = n-1;
    } else {
        i = m % n;
        i--;
    }
    currtime = arrivals[i];
    
    for (; i < m; i += n) {
        trips++;
        currtime = max(currtime, arrivals[i]) + 2 * t;
    }

    currtime -= t;
    cout << currtime << " " << trips << endl;
}


