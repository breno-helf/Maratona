n , m = map(int, input().split())
s = []
resp = 0
atual = 0
for i in range (0, n):
    s.append(input())
for i in range (0, n):
    if i % 2:
        for j in s[i][::-1]:
            if j == '.':
                atual += 1
            elif j == 'L':
                atual = 0
            if atual > resp:
                resp = atual
    else:
        for j in s[i]:
            if j == '.':
                atual += 1
            elif j == 'L':
                atual = 0
            if atual > resp:
                resp=  atual
print(int(resp))                
