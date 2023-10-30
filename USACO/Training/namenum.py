"""
ID: wangxin22
TASK: namenum
LANG: PYTHON3
"""

with open("dict.txt") as f:
    names = [name.rstrip() for name in f.readlines()]

with open("namenum.in") as i:
    num = i.readline().rstrip()

with open("namenum.out", "w") as o:
    for name in names:
        if len(name) == len(num):
            for k, v in zip(num, name):
                if v not in {
                    "2": ["A", "B", "C"],
                    "3": ["D", "E", "F"],
                    "4": ["G", "H", "I"],
                    "5": ["J", "K", "L"],
                    "6": ["M", "N", "O"],
                    "7": ["P", "R", "S"],
                    "8": ["T", "U", "V"],
                    "9": ["W", "X", "Y"],
                }[k]:
                    break
            else:
                print(name, file=o)
    if not o.tell():
        print("NONE", file=o)
