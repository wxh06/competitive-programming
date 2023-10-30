"""
ID: wangxin22
TASK: dualpal
LANG: PYTHON3
"""


def to_base(n: int, b: int) -> str:
    return f"{to_base(n // b, b)}{n % b}".lstrip("0") if n else "0"


with open("dualpal.in") as i:
    n, s = (int(i) for i in i.readline().rstrip().split())

with open("dualpal.out", "w") as o:
    c = 0
    while c < n:
        s += 1
        if [
            (lambda s: s == s[::-1])(to_base(s, b)) for b in range(2, 11)
        ].count(True) > 1:
            print(s, file=o)
            c += 1
