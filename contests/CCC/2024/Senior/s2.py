t = int(input().split()[0])

while t:
    t -= 1

    s, cnt = input(), {}
    for ch in s:
        if ch in cnt:
            cnt[ch] += 1
        else:
            cnt[ch] = 1
    heavy = cnt[s[0]] > 1
    for ch in s:
        if (cnt[ch] > 1) != heavy:
            print("F")
            break
        heavy = not heavy
    else:
        print("T")
