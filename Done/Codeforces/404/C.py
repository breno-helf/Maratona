n, m = map(int, input().split())
l = m
r = 2 * (10 ** 18) + 20

while (l < r):
    k = (l + r) // 2
    num = ((k - m) * (k + m + 1)) // 2 - (k - m - 1) * m
        
    if (num < n):
        l = k + 1
    else:
        r = k

if (n <= m):
    print(n)
else:
    print(l)
    
