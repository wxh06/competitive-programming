s = "".join([f"{ord(c):08b}" for c in input()])

i = 0
while True:
    d = f"{i:b}"
    if d not in s:
        break
    s = s.replace(d, "", 1)[::-1].replace(d[::-1], "", 1)[::-1]
    i += 1

s = f"{int(s, 2):o}"

i = 0
while True:
    d = f"{i:o}"
    if d not in s:
        break
    s = s.replace(d, "", 1)[::-1].replace(d[::-1], "", 1)[::-1]
    i += 1

print(i - 1)
