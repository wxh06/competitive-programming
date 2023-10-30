def feed(n, h, m):
    for i in range(n - 1):
        h[i + 1] -= h[i] - m
        h[i] = m
        if h[i + 1] < m:
            break
    if h.count(m) == n:
        return sum(h)
    return -1


t = int(input())
for _ in range(t):
    n = int(input())
    h = [int(h) for h in input().split()]
    minimum = min(h)
    if n % 2 or feed(n, h.copy(), 0) >= 0:
        for m in range(minimum, -1, -1):
            c = feed(n, h.copy(), m)
            if c >= 0:
                print(sum(h) - c)
                break
        else:
            print(-1)
    else:
        print(-1)
