"""
ID: wangxin22
TASK: skidesign
LANG: PYTHON3
"""

with open("skidesign.in") as f:
    n, a = int(f.readline().rstrip()), []
    for i in range(n):
        a.append(int(f.readline().rstrip()))
with open("skidesign.out", "w") as f:
    print(
        min(
            [
                sum(
                    min(abs(i - ai), abs(i + 17 - ai)) ** 2
                    for ai in a
                    if ai > i + 17 or ai < i
                )
                for i in range(min(a), max(a) - 16)
            ]
            or [0]
        ),
        file=f,
    )
