c = [[-1 for x in range(300)] for y in range(300)]

def bi(n, k):
    
    if (c[n][k] != -1):
        return c[n][k]
    if (k == 1):
        return n
    if (k == n):
        return 1

    c[n][k] = bi(n - 1, k - 1) + bi(n - 1, k)
    return c[n][k]

dp = ([-1]*300)
pot = [0]*300
fat = [0]*300

pot[0] = 1
fat[0] = 1

for i in range (1, 210):
    pot[i] = pot[i - 1]*2
    fat[i] = fat[i - 1]*i

dp[0] = dp[1] = 1
    
def solve(n):
    if(dp[n] != -1):
        return dp[n]

    add = pot[n]*fat[n]
    sum = 0

    for i in range(1, n + 1):
        sum += bi(n, i)*solve(n - i)

    dp[n] = add - sum
    return dp[n]

fi = open("derangements.in", "r")
fo = open("derangements.out", "w")


inp = int(fi.read())

fo.write(str(solve(inp)))
