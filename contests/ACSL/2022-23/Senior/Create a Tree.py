from bisect import bisect_left

s = input()
a1, a2 = [], []

for c in s:
    p = bisect_left(a1, c)
    a1.insert(p, c)
    a2.insert(p, (((a2[-1] if p == len(a2) else max(a2[p - 1], a2[p])) if p else a2[0]) + 1) if len(a2) else 0)

s1, s2 = "", ""


def find(l, r, v):
    try:
        p = a2[l:r].index(v) + l
        global s1, s2
        s1 += a1[p]
        find(l, p, v + 1)
        find(p + 1, r, v + 1)
        s2 += a1[p]
    except ValueError:
        pass


find(0, len(s), 0)
print(s1, s2)
