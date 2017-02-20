from math import factorial as fac

def bin (x, y):
    return fac(x) // (fac(y)*fac(x - y))

n, d = map(float, input().split())
p = 0.521531100478468
resp = 0
for i in range(3, 7):
    resp += bin(6, i)*(p**(i))*((1 - p)**(6 - i))
    
print(format(resp, '.3f'))
