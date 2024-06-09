
n = int(input())
md = 998244353
numdigits = 0
tmp = n
while (tmp > 0):
    numdigits += 1
    tmp //= 10
    
ans = n * (pow(10, n * numdigits, md)-1) * pow(pow(10, numdigits)-1, md-2, md)
ans %= md

print(ans)

