"""
ID: wangxin22
TASK: friday
LANG: PYTHON3
"""

from datetime import date, timedelta


with open("friday.in") as i:
    n = int(i.read().rstrip())
d = date(1900, 1, 1)
w = [0] * 7

while d.year < 1900 + n:
    if d.day == 13:
        w[d.weekday()] += 1
    d += timedelta(days=1)

with open("friday.out", "w") as o:
    print(" ".join(str(w[(i + 5) % 7]) for i in range(7)), file=o)
