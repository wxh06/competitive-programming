import math


def solve(tc, tm, a, b, c, t):
    """
    :type tc: int
    :type tm: int
    :type a: list[int]
    :type b: list[int]
    :type c: list[int]
    :type t: int
    """
    x, y = 0, 0
    for ai, bi, ci in zip(a, b, c):
        left = ai * tc + bi * tm - ci
        if ai > bi:
            min_x = math.ceil((left - bi * t) / (ai - bi))
            min_x = max(min_x, 0)
            x = max(x, min_x)
        elif ai < bi:
            min_y = math.ceil((left - ai * t) / (bi - ai))
            min_y = max(min_y, 0)
            y = max(y, min_y)
        else:
            if ai * t < left:
                return False
            min_x = left - tm + 1
            min_y = left - tc + 1
            min_x = max(min_x, 0)
            x = max(x, min_x)
            min_y = max(min_y, 0)
            y = max(y, min_y)
        if x + y > t or x >= tc or y >= tm:
            return False
    return True


t = int(input())
for _ in range(t):
    input()
    a, b, c = [], [], []
    n, tc, tm = map(int, input().split())
    for i in range(n):
        ai, bi, ci = map(int, input().split())
        a.append(ai)
        b.append(bi)
        c.append(ci)
    l, r = 0, tc + tm - 2
    while l < r:
        m = (l + r) // 2
        if solve(tc, tm, a, b, c, m):
            r = m
        else:
            l = m + 1
    print(l)
