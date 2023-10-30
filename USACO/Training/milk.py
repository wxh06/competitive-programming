"""
ID: wangxin22
TASK: milk
LANG: PYTHON3
"""

import sys
from operator import itemgetter

sys.stdin = open("milk.in")
sys.stdout = open("milk.out", "w")

n, m = map(int, input().split())
f = []
for i in range(m):
    f.append(tuple(map(int, input().split())))

f.sort(key=itemgetter(0))

p, a = 0, 0
for i in f:
    if a + i[1] >= n:
        p += (n - a) * i[0]
        break
    p += i[0] * i[1]
    a += i[1]
print(p)
