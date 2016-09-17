k = 1
m = 2
n = int(input())
i = 0
while (i < n):
    a = ((k+1)*(k+1)*k*k - m)/k
    print(int(a))
    m = (k + 1)*k
    k = k + 1
    i = i + 1

