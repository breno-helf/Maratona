fat = [0] * 200
fat[0] = 1

for i in range (1, 100):
    fat[i] = fat[i - 1]*i
    
d, h = map(int, input().split())

p = []

def gen (num, i, last, tot):
    if (i == d):
        prod = int(fat[h - 1])
        for v in num:
            prod = int(int(prod)//int(fat[v]))
        if not int(prod) in p:
            p.append(prod)
    else:
        if (i + 1 == d):
            ini = tot
        else:
            ini = last
        num[i] = ini
        while(num[i] <= tot):
            gen(num, i + 1, num[i], tot - num[i])
            num[i] += 1
        

calc = [0]*d

gen(calc, 0, 0, h - 1)

#p = []

#for x in resp.keys():
#    p.append(x)

p.sort()

for x in p:
    print(int(x))
