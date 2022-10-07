#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

/*
   Thought process: 

   Idea 1:
   Seems sort of like greedy dp question
   It is clear that choosing routers is the best way to go...
   Maybe I could make an array that spans the entire bounds
   for every router, I put a 1 and -1 at the endpoLLs
   Find the prefix sums, then we will get all the overlapping 
   hotspots.

   All the spots with a '1' is it's effective range. 
   Now we want to iterate through the array, and use a new array to 
   depict the LEFT most 1. Then use the array to depict the RIGHTmost 1. 
   We then iterate through these 2 arrays and decide whether each
   router is worth, assuming all routers are on... This should 
   theoretically work because they all have the same range. If two
   are next to each other, we'll see that one of them pretty
   much gets fully engulfed, so we don't actually want to take the
   left one of that router. Then after that, we do this process one
   more time with all the on-routers and sum the non-connected rooms.

   OK this doesn't work because of 0001111111000, we don't know which
   routers in the middle to turn on/off because theyre ALL overlapping

   Idea 2: 
   Fine... Ill just do normal DP. I'll just do the problem statement
   but smaller, which is basically every DP in existence
   It has to be linear, so the DP could be
   What is the minimum cost of connecting all 1..i rooms? For each
   dp[i].

   To build on this dp:
   dp[i] += 0 if there exists a router from max(1, i-k) to i, we 
   would rather just purchase this router instead of our own room
   + i if there does not exist a router within this distance.
   The question is how do we know if the router is on and if it
   was already counted? we can force it to happen going
   dp[that router-1] + that router. So we have the min cost of 
   everything up to that router, then add that router on. 
   
   To find that router, Ill just keep all the routers in a std::set
   and use lower bound on it. This should be NlogN which should work.

   Idea 3:
   I'll do the same thing, but backwards because 
   of the indexing and router selection priority...
   Means we go forwards instead of backwards


*/

#define INFIN numeric_limits<LL>::max() / 2

const LL MX = 2 * 1e5 + 100;
LL dp[MX];
set<LL> routers;

void Debug(LL n) {
    for (LL i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}


void solve() {
    LL n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (LL i = 0; i < n; i++) {
        char c = s[i];
        if (c == '1') {
            routers.insert(i+1);
        }
    }
    for (LL i = 1; i <= n; i++) {
        dp[i] = INFIN;
    }
    for (LL i = n; i >= 1; i--) {
        auto it = routers.lower_bound(i - k);
        LL next = *it;
    }   

    for (LL i = n; i >= 1; i--) {
        auto it = routers.lower_bound(i - k);
        LL next = *it;
        //cout << next << " ";
        if (it == routers.end()) {
            dp[i] = min(dp[i], dp[i+1] + i);
        } else if ((next > i && next - i > k) || next == 0) {
            dp[i] = min(dp[i], dp[i+1] + i);
        } else {
            dp[i] = min(dp[i], dp[i+1]+i);
            LL tmp = dp[i+1] + next;
            LL idx = max((LL)1, next-k);
            dp[idx] = min(dp[idx], tmp);
            dp[i] = min(dp[i], tmp);
            dp[i] = min(dp[i], dp[idx]);
        }
    }
    //Debug(n);
    
   
    cout << dp[1] << '\n';
}

