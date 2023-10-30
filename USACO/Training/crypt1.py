"""
ID: wangxin22
TASK: crypt1
LANG: PYTHON3
"""

import sys

sys.stdin = open("crypt1.in")
n = int(input())
a = list(map(int, input().split()))
sys.stdin.close()

c = 0
for i1 in a:
    for i2 in a:
        for i3 in a:
            for j in a:
                for k in a:
                    l1 = i1 * 100 + i2 * 10 + i3
                    l2 = j * 10 + k
                    l3 = str(l1 * j).lstrip("0")
                    l4 = str(l1 * k).lstrip("0")
                    l5 = str(l1 * l2).lstrip("0")
                    for i in l3 + l4 + l5:
                        if int(i) not in a:
                            break
                    else:
                        if len(l3) == 3 and len(l4) == 3 and len(l5) == 4:
                            c += 1

with open("crypt1.out", "w") as f:
    print(c, file=f)
