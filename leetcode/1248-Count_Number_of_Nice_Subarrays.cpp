class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        d = {}
        count = 0
        ans = 0
        d[0] = 1
        for i in nums:
            if i % 2 == 1:
                count += 1

            x = count - k
            if x in d:
                ans += d[x]

            if count in d:
                d[count] += 1
            else:
                d[count] = 1

        return ans

# d[2] = the number of 2s that we have seen before
# d[0] = 3
# d[1] = 3
# d[2] = 4
# d[3] = 3

# 2 2 2 1 2 2 1 2 2 2 1 2 2
# 0 0 0 1 1 1 2 2 2 2 3 3 3

# 1 1 2 1 1
# 1 2 2 3 4
