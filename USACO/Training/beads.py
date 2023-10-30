"""
ID: wangxin22
TASK: beads
LANG: PYTHON3
"""


def beads(n, b):
    for _ in range(n):
        yield b
        b = b[-1] + b[0:-1]


with open("beads.in") as i:
    n = int(i.readline().rstrip())
    b = i.readline().rstrip()
with open("beads.out", "w") as o:
    try:
        print(
            max(
                [
                    (
                        lambda b: n
                        - len(
                            b.lstrip(f"{b.lstrip('w')[0]}w").rstrip(
                                f"{b.rstrip('w')[-1]}w"
                            )
                        )
                    )(bead)
                    for bead in beads(n, b)
                ]
            ),
            file=o,
        )
    except IndexError:
        print(n, file=o)
