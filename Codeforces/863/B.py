n = int(input())
w = list(map(int, input().split()))
w.sort()
r = 1000000
for i in range(n * 2 - 1):
    for j in range(i, n * 2 - 1):
        d = w.copy()
        del d[i]
        del d[j]
        r = min(r, sum([d[k] - d[k - 1] for k in range(1, len(d), 2)]))
print(r)
