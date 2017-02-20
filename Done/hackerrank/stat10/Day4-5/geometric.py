from math import factorial as fac

n, d = map(int, input().split(' '))
idx = int(input())

resp = 0.0
p *= n / d

print(format(p*(1 - p)**(idx - 1), '.3f'))

