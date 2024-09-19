class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        l1 = s1.split()
        l2 = s2.split()
        n = len(l1)
        m = len(l2)
        if n > m:
            s2, s1 = s1, s2
            l2, l1 = l1, l2
            n, m = m, n
        if n == m:
            return l1 == l2
        # 3 cases, s2 =
        # insert s1
        # s1 insert s1
        # s1 insert
        # since bounds are small, we can brute force
        # for all inserts range from i, j.
        for i in range(m):
            for j in range(i, m):
                if m - (j-i+1) != n:
                    continue
                if i == 0 and j < m-1 and l2[j+1:] == l1:
                    return True
                elif i > 0 and j == m-1 and l2[0:i] == l1:
                    return True
                elif i > 0 and j < m-1:
                    if l2[0:i] == l1[0:i] and l2[j+1:] == l1[i:]:
                        return True

        return False
