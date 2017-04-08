MAX = 1123
t = int(input())
for q in range(t):
    n, k = map(int, input().split())
    l = [MAX] * MAX
    r = [MAX] * MAX
    o = [0] * MAX
    for i in range(n):
        l[i] = i
        r[i] = n - i - 1
        #print (str(l[i]), str(r[i]), end = ' --- ')

    #print("")
    for person in range(k):
        idx = -1
        d = -1
        m = -1
        for i in range(n):
            if (o[i] == 0):
                if (min(l[i], r[i]) > d):
                    d = min(l[i], r[i])
                    idx = i
                    m = max(l[i], r[i])
                elif (min(l[i], r[i]) == d and max(l[i], r[i]) > m):
                    d = min(l[i], r[i])
                    idx = i
                    m = max(l[i], r[i])
                    

        #print("---> " + str(idx))
        o[idx] = 1
        last = idx
        for i in range(idx - 1, -1, -1):
            r[i] = min(r[i], idx - 1 - i)
        for i in range(idx + 1, n):
            l[i] = min(l[i], i - (idx + 1))

        #for i in range(n):
            #print (str(l[i]), str(r[i]), end = ' --- ')


    f = max(r[last], l[last])
    s = min(r[last], l[last])
    print("Case #" + str(q + 1) + ": " + str(f), str(s))
