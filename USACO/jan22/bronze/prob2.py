t = int(input())


def beats(x: list, y: list) -> bool:
    return [i > j for i in x for j in y].count(True) > [
        i < j for i in x for j in y
    ].count(True)


def enum(a: list, b: list) -> bool:
    for i1 in range(1, 11):
        for i2 in range(i1, 11):
            for i3 in range(i2, 11):
                for i4 in range(i3, 11):
                    c = [i1, i2, i3, i4]
                    if (beats(a, b) and beats(c, a) and beats(b, c)) or (
                        beats(b, a) and beats(c, b) and beats(a, c)
                    ):
                        return True
    return False


for _ in range(t):
    a, b = (lambda n: (n[:4], n[4:]))([int(n) for n in input().split()])
    if enum(a, b):
        print("yes")
    else:
        print("no")
