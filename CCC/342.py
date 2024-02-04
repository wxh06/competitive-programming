same = []
for i in range(int(input())):
    same.append(input().split())

separate = []
for i in range(int(input())):
    separate.append(input().split())

teams = {}
for i in range(int(input())):
    s1, s2, s3 = input().split()
    teams[s1] = [s2, s3]
    teams[s2] = [s1, s3]
    teams[s3] = [s1, s2]

cnt = 0
for s1, s2 in same:
    cnt += (s2 not in teams[s1])
for s1, s2 in separate:
    cnt += (s2 in teams[s1])
print(cnt)
