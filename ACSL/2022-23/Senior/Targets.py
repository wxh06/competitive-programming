n = int(input())
t = list(map(lambda i: (int(i[0]), int(i[1])), input().split()))
c = list(map(lambda i: list(map(int, i)), input().split()))
d = [
    (0, -1),
    (-1, 0),
    (0, +1),
    (+1, 0),
    (-1, -1),
    (-1, +1),
    (+1, +1),
    (+1, -1),
]
a = list(map(lambda i: (int(i[0]), int(i[1]), d[ord(i[2]) - ord("A")]), input().split()))

for i in a:
    x, y, o = i
    c[0][x] -= 1
    c[1][y] -= 1
    while True:
        b = False
        x += o[0]
        y += o[1]
        if not (0 <= x < n and 0 <= y < n):
            break
        for j in a:
            if (x, y) == j[0:2]:
                b = True
                break
        if b:
            break
        try:
            t.remove((x, y))
            break
        except ValueError:
            pass

x, y = c[0].index(1), c[1].index(1)
dx = t[0][0] - x
dy = t[0][1] - y
for i in range(len(d)):
    if (dx * d[i][0] > 0 or dx == d[i][0]) and (dy == d[i][1] or dy * d[i][1] > 0):
        print(x, y, chr(i + ord("A")), sep="")
