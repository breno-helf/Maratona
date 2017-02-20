from math import factorial as fac
from math import exp

lamb = float(input())
k = int(input())

print(format((exp(-lamb)*lamb**k)/fac(k)))
