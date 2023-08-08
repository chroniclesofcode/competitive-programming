class Solution {
public:
    /*
       This question is hard to understand if you are
       unfamiliar with bitmasks. This is a question about
       transitions - it is DP, but you shouldn't think of
       it in a traditional DP way based on recursive states.

       Sorry if it's a bit long - I think it's hard to
       articulate the solution to this question in a clear
       way while being succinct. 

       So this question is actually about counting the
       differences between two states in a string. So first
       we have a bitmask that represents if the count of a
       certain letter is even or odd (1 = odd, 0 = even,
       everything originally starts as even so all 0s).

       Our first step is to count the occurence of each mask
       (I know in the CODE, this is the last step, but
       it's actually the first step). Next, every time we
       iterate through the code, we need to observe the
       differences between the current mask, and every mask
       that has occured in the past.

       The idea is you add to the answer the number of times
       this mask has occured in the past. The first time
       the mask occurs, nothing will get added, but the
       consecutive times, it will keep building +2, +3 etc.
       The reason is because IF your current mask has occured before,
       that means the count of every single letter starting
       from there was even up until your current mask, because
       you ended up with the same mask. This is the first case
       where all characters are even, you need to do
       ans += count[mask];

       Now you have to consider where all the characters are even
       except for one. This is where the DP logic falls through a
       bit. Usually we want to try to build on previous steps and
       think about what is the transition to get here, or do a
       mathematical calculation to get all the possible substrings
       in one go. But that is not really the solution. You have to
       flip the bits of every single character, and check if the
       flipped mask has existed before, and add the number of
       occurences (similar to the all-evens). The difference this time
       is that FROM the last time the mask occured UP UNTIL your
       current mask, since the bit difference is only 1, that means
       there is an even number of characters + that singular
       difference that you manually created - you are checking
       if this mask existed or not. So you are not checking DP
       from the beginning traditionally, but since the last time
       a certain mask occured. This previous mask + difference
       will guaranteed to be even + a difference of one odd character.

       Hopefully this makes sense, the code should also make it a bit
       more clear. 
    */
    int count[(int)1e5+1];
    long long wonderfulSubstrings(string word) {
        // 1 = odd, 0 = even
        int mask = 0;
        count[0] = 1;
        long long ans = 0;
        for (int i = 0; i < word.length(); i++) {
            int ch = word[i] - 'a';
            mask = mask ^ (1 << ch);
            ans += count[mask];
            for (int i = 0; i < 10; i++) {
                ans += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }
        return ans;
    }
};
