from math import factorial as fac

def bin (x, y):
    return fac(x) // (fac(y)*fac(x - y))

resp = 0

n, d = map(float, input().split())
idx = int(input())

p = n / d

for i in range(1, idx + 1):
    resp += p*(1 - p)**(i - 1)

print(format(resp, '.3f'))
