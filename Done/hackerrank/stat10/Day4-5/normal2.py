from math import exp
from math import sqrt
from math import acos
from math import erf
PI = acos(-1)

def calc(x, M, SD):
    return .5 * (1 + erf((x - M)/(SD*sqrt(2))))

m, sd = map(int, input().split())
good = float(input())
avrg = float(input())

print(format(1 - calc(good, m, sd), '.3f'))

print(format(1 - calc(avrg, m, sd), '.3f'))
print(format(calc(avrg, m, sd), '.3f'))
    
