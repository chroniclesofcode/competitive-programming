class Solution {
public:
    /*
       This question was a bit of a hassle to do - O(n^2) is
       allowed but I had a feeling it was do-able in O(n).

       The idea is every second we're shifting a 1 over to the
       left if it is replacing a 0. However, if there is a queue
       of 1's, then each 1 will be added to a block variable
       since we have to keep waiting. If we encounter a 0
       then we will subtract 1 from block since it will
       allow the next 1 to catch up. Not really that easy
       in my opinion, but easy enough for me to do without
       assistance :)
    */
    int secondsToRemoveOccurrences(string s) {
        int i = 0;
        while (s[i] == '1') {
            i++;
        }
        int block = 0;
        int ans = 0;
        int n0 = 0;
        for (; i < s.size(); i++) {
            if (s[i] == '1') {
                ans = max(ans, block + n0);
                block++;
            } else {
                n0++;
                block = max(block-1, 0);
            }
        }
        return ans;
    }
};
