"""
ID: wangxin22
TASK: palsquare
LANG: PYTHON3
"""


def to_base(n, b):
    return (
        to_base(n // b, b).lstrip("0") + "0123456789ABCDEFGHIJ"[n % b]
        if n
        else "0"
    )


with open("palsquare.in") as i:
    b = int(i.readline().rstrip())
with open("palsquare.out", "w") as o:
    for i in range(1, 301):
        s = to_base(i ** 2, b)
        if s == s[::-1]:
            print(to_base(i, b), s, file=o)
