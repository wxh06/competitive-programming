import re
import string

indexed = list(filter(lambda s: s.strip(), re.split(r"(\W)", input())))
unimportant = list(string.punctuation) + input().split()
important = [False if s.lower() in unimportant else True for s in indexed]
start, end = map(int, input().split())
table = []

for i in range(len(indexed)):
    if not important[i]:
        continue
    j = i - 1
    while i - j <= 3 and important[j]:
        j -= 1
    k = i + 1
    while k - i <= 3 and k < len(indexed) and important[k]:
        k += 1
    table.append(
        (" ".join(indexed[j + 1 : i]), indexed[i], " ".join(indexed[i + 1 : k]))
    )
table.sort(key=lambda r: r[1].lower())

max_len = [0, 0, 0]
length = []
for r in table:
    for i in range(3):
        max_len[i] = max(max_len[i], len(r[i]))
    length.append(sum(map(len, r)))

row = table[length.index(max(length[start - 1 : end]), start - 1, end)]
print(
    row[0].rjust(max_len[0], "-"),
    "<" + row[1].ljust(max_len[1], "-") + ">",
    row[2].ljust(max_len[2], "-"),
)
