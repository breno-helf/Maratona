from math import factorial as fac

def bin (x, y):
    return fac(x) // (fac(y)*fac(x - y))

p, n = map(int, input().split(' '))
resp = 0.0
p *= 0.01

for i in range(3):
    resp += bin(n, i)*(p**i)*((1 - p)**(n - i))

print(format(resp, '.3f'))

resp = 0.0
for i in range(2, 11):
    resp += bin(n, i)*(p**i)*((1 - p)**(n - i))
    
print(format(resp, '.3f'))
