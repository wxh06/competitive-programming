"""
ID: wangxin22
TASK: barn1
LANG: PYTHON3
"""

import sys

sys.stdin = open("barn1.in")
sys.stdout = open("barn1.out", "w")

m, s, c = map(int, input().split())
o = []
for i in range(c):
    o.append(int(input()))
o.sort()
d = []
for i in range(c - 1):
    d.append(o[i + 1] - o[i] - 1)
d.sort(reverse=True)
print(o[-1] - o[0] + 1 - sum(d[: m - 1]))
